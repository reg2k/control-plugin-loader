/*
DLL Loader by reg2k
Plugins are loaded on entry into the process entry point.
This ensures all linked libraries have already been loaded when plugins are initialized.
*/
#include "main.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <string>

#include "Config_Control.h"
#include "Logger.h"
#include "minhook/include/MinHook.h"

static Logger g_logger;

namespace DLL_Loader {
    // Hooks
    int (*EntryPoint_Original)(void) = nullptr;

    void LoadDLL(const std::string& pluginName) {
        char pluginPath[MAX_PATH];
        snprintf(pluginPath, MAX_PATH, "%s\\%s", PLUGINS_DIR, pluginName.c_str());

        _LOG("Loading plugin: %s", pluginName.c_str());
        HMODULE hMod = LoadLibraryA(pluginPath);
        if (!hMod) {
            _LOG("> Failed to load plugin. Error code: 0x%X.", GetLastError());
        }
    }

    // Given a directory, returns the list of files in it.
    std::vector<std::string> GetFileList(const char* dir, const char* pattern = "*") {
        std::vector<std::string> fileList;
        HANDLE hFind;
        WIN32_FIND_DATAA findData;

        char findStr[MAX_PATH];
        snprintf(findStr, MAX_PATH, "%s\\%s", dir, pattern);

        hFind = FindFirstFileA(findStr, &findData);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if (!strcmp(findData.cFileName, ".") || !strcmp(findData.cFileName, "..")) continue;
                if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;

                fileList.emplace_back(findData.cFileName);

            } while (FindNextFileA(hFind, &findData));
            FindClose(hFind);
        }
        return fileList;
    }

    int EntryPoint_Hook() {
        // Get all DLLs in folder
        auto pluginList = GetFileList(PLUGINS_DIR, "*.dll");
        _LOG("Number of installed plugins: %d", pluginList.size());

        // Load plugins
        for (auto const& pluginName : pluginList) {
            LoadDLL(pluginName);
        }

        return EntryPoint_Original();
    }
}

void start() {
    using namespace DLL_Loader;

    // Initialize logger
    char szLogPath[MAX_PATH] = "";
    ExpandEnvironmentStringsA(LOG_PATH, szLogPath, sizeof(szLogPath));
    g_logger.Open(szLogPath);
    _LOG("%s v%s by reg2k", MODULE_NAME_LONG, MODULE_VERSION_STRING);

    // Get process entry point
    HMODULE hMod = GetModuleHandleA(NULL);
    IMAGE_DOS_HEADER* pDOSHeader = reinterpret_cast<IMAGE_DOS_HEADER*>(hMod);
    IMAGE_NT_HEADERS* pNTHeaders = reinterpret_cast<IMAGE_NT_HEADERS*>((char*)pDOSHeader + pDOSHeader->e_lfanew);
    DWORD entryPointRVA = pNTHeaders->OptionalHeader.AddressOfEntryPoint;
    void* entryPoint = (char*)hMod + entryPointRVA;
    _LOG("Module base: %p", hMod);
    _LOG("Process entry point at %p", entryPoint);

    // Hook entry point
    MH_Initialize();
    MH_CreateHook(entryPoint, EntryPoint_Hook, reinterpret_cast<LPVOID*>(&EntryPoint_Original));
    if (MH_EnableHook(entryPoint) != MH_OK) {
        _LOG("FATAL: Failed to install entry point hook.");
        return;
    }
}
