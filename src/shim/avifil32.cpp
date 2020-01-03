#include <windows.h>
#include "../main.h"

static HMODULE g_hModule = NULL;

extern "C" {
	FARPROC O_AVIBuildFilter;
	FARPROC O_AVIBuildFilterA;
	FARPROC O_AVIBuildFilterW;
	FARPROC O_AVIClearClipboard;
	FARPROC O_AVIFileAddRef;
	FARPROC O_AVIFileCreateStream;
	FARPROC O_AVIFileCreateStreamA;
	FARPROC O_AVIFileCreateStreamW;
	FARPROC O_AVIFileEndRecord;
	FARPROC O_AVIFileExit;
	FARPROC O_AVIFileGetStream;
	FARPROC O_AVIFileInfo;
	FARPROC O_AVIFileInfoA;
	FARPROC O_AVIFileInfoW;
	FARPROC O_AVIFileInit;
	FARPROC O_AVIFileOpen;
	FARPROC O_AVIFileOpenA;
	FARPROC O_AVIFileOpenW;
	FARPROC O_AVIFileReadData;
	FARPROC O_AVIFileRelease;
	FARPROC O_AVIFileWriteData;
	FARPROC O_AVIGetFromClipboard;
	FARPROC O_AVIMakeCompressedStream;
	FARPROC O_AVIMakeFileFromStreams;
	FARPROC O_AVIMakeStreamFromClipboard;
	FARPROC O_AVIPutFileOnClipboard;
	FARPROC O_AVISave;
	FARPROC O_AVISaveA;
	FARPROC O_AVISaveOptions;
	FARPROC O_AVISaveOptionsFree;
	FARPROC O_AVISaveV;
	FARPROC O_AVISaveVA;
	FARPROC O_AVISaveVW;
	FARPROC O_AVISaveW;
	FARPROC O_AVIStreamAddRef;
	FARPROC O_AVIStreamBeginStreaming;
	FARPROC O_AVIStreamCreate;
	FARPROC O_AVIStreamEndStreaming;
	FARPROC O_AVIStreamFindSample;
	FARPROC O_AVIStreamGetFrame;
	FARPROC O_AVIStreamGetFrameClose;
	FARPROC O_AVIStreamGetFrameOpen;
	FARPROC O_AVIStreamInfo;
	FARPROC O_AVIStreamInfoA;
	FARPROC O_AVIStreamInfoW;
	FARPROC O_AVIStreamLength;
	FARPROC O_AVIStreamOpenFromFile;
	FARPROC O_AVIStreamOpenFromFileA;
	FARPROC O_AVIStreamOpenFromFileW;
	FARPROC O_AVIStreamRead;
	FARPROC O_AVIStreamReadData;
	FARPROC O_AVIStreamReadFormat;
	FARPROC O_AVIStreamRelease;
	FARPROC O_AVIStreamSampleToTime;
	FARPROC O_AVIStreamSetFormat;
	FARPROC O_AVIStreamStart;
	FARPROC O_AVIStreamTimeToSample;
	FARPROC O_AVIStreamWrite;
	FARPROC O_AVIStreamWriteData;
	FARPROC O_CreateEditableStream;
	FARPROC O_DllCanUnloadNow;
	FARPROC O_DllGetClassObject;
	FARPROC O_EditStreamClone;
	FARPROC O_EditStreamCopy;
	FARPROC O_EditStreamCut;
	FARPROC O_EditStreamPaste;
	FARPROC O_EditStreamSetInfo;
	FARPROC O_EditStreamSetInfoA;
	FARPROC O_EditStreamSetInfoW;
	FARPROC O_EditStreamSetName;
	FARPROC O_EditStreamSetNameA;
	FARPROC O_EditStreamSetNameW;
	FARPROC O_IID_IAVIEditStream;
	FARPROC O_IID_IAVIFile;
	FARPROC O_IID_IAVIStream;
	FARPROC O_IID_IGetFrame;
}

static void PopulateAddresses() {
	O_AVIBuildFilter = GetProcAddress(g_hModule, "AVIBuildFilter");
	O_AVIBuildFilterA = GetProcAddress(g_hModule, "AVIBuildFilterA");
	O_AVIBuildFilterW = GetProcAddress(g_hModule, "AVIBuildFilterW");
	O_AVIClearClipboard = GetProcAddress(g_hModule, "AVIClearClipboard");
	O_AVIFileAddRef = GetProcAddress(g_hModule, "AVIFileAddRef");
	O_AVIFileCreateStream = GetProcAddress(g_hModule, "AVIFileCreateStream");
	O_AVIFileCreateStreamA = GetProcAddress(g_hModule, "AVIFileCreateStreamA");
	O_AVIFileCreateStreamW = GetProcAddress(g_hModule, "AVIFileCreateStreamW");
	O_AVIFileEndRecord = GetProcAddress(g_hModule, "AVIFileEndRecord");
	O_AVIFileExit = GetProcAddress(g_hModule, "AVIFileExit");
	O_AVIFileGetStream = GetProcAddress(g_hModule, "AVIFileGetStream");
	O_AVIFileInfo = GetProcAddress(g_hModule, "AVIFileInfo");
	O_AVIFileInfoA = GetProcAddress(g_hModule, "AVIFileInfoA");
	O_AVIFileInfoW = GetProcAddress(g_hModule, "AVIFileInfoW");
	O_AVIFileInit = GetProcAddress(g_hModule, "AVIFileInit");
	O_AVIFileOpen = GetProcAddress(g_hModule, "AVIFileOpen");
	O_AVIFileOpenA = GetProcAddress(g_hModule, "AVIFileOpenA");
	O_AVIFileOpenW = GetProcAddress(g_hModule, "AVIFileOpenW");
	O_AVIFileReadData = GetProcAddress(g_hModule, "AVIFileReadData");
	O_AVIFileRelease = GetProcAddress(g_hModule, "AVIFileRelease");
	O_AVIFileWriteData = GetProcAddress(g_hModule, "AVIFileWriteData");
	O_AVIGetFromClipboard = GetProcAddress(g_hModule, "AVIGetFromClipboard");
	O_AVIMakeCompressedStream = GetProcAddress(g_hModule, "AVIMakeCompressedStream");
	O_AVIMakeFileFromStreams = GetProcAddress(g_hModule, "AVIMakeFileFromStreams");
	O_AVIMakeStreamFromClipboard = GetProcAddress(g_hModule, "AVIMakeStreamFromClipboard");
	O_AVIPutFileOnClipboard = GetProcAddress(g_hModule, "AVIPutFileOnClipboard");
	O_AVISave = GetProcAddress(g_hModule, "AVISave");
	O_AVISaveA = GetProcAddress(g_hModule, "AVISaveA");
	O_AVISaveOptions = GetProcAddress(g_hModule, "AVISaveOptions");
	O_AVISaveOptionsFree = GetProcAddress(g_hModule, "AVISaveOptionsFree");
	O_AVISaveV = GetProcAddress(g_hModule, "AVISaveV");
	O_AVISaveVA = GetProcAddress(g_hModule, "AVISaveVA");
	O_AVISaveVW = GetProcAddress(g_hModule, "AVISaveVW");
	O_AVISaveW = GetProcAddress(g_hModule, "AVISaveW");
	O_AVIStreamAddRef = GetProcAddress(g_hModule, "AVIStreamAddRef");
	O_AVIStreamBeginStreaming = GetProcAddress(g_hModule, "AVIStreamBeginStreaming");
	O_AVIStreamCreate = GetProcAddress(g_hModule, "AVIStreamCreate");
	O_AVIStreamEndStreaming = GetProcAddress(g_hModule, "AVIStreamEndStreaming");
	O_AVIStreamFindSample = GetProcAddress(g_hModule, "AVIStreamFindSample");
	O_AVIStreamGetFrame = GetProcAddress(g_hModule, "AVIStreamGetFrame");
	O_AVIStreamGetFrameClose = GetProcAddress(g_hModule, "AVIStreamGetFrameClose");
	O_AVIStreamGetFrameOpen = GetProcAddress(g_hModule, "AVIStreamGetFrameOpen");
	O_AVIStreamInfo = GetProcAddress(g_hModule, "AVIStreamInfo");
	O_AVIStreamInfoA = GetProcAddress(g_hModule, "AVIStreamInfoA");
	O_AVIStreamInfoW = GetProcAddress(g_hModule, "AVIStreamInfoW");
	O_AVIStreamLength = GetProcAddress(g_hModule, "AVIStreamLength");
	O_AVIStreamOpenFromFile = GetProcAddress(g_hModule, "AVIStreamOpenFromFile");
	O_AVIStreamOpenFromFileA = GetProcAddress(g_hModule, "AVIStreamOpenFromFileA");
	O_AVIStreamOpenFromFileW = GetProcAddress(g_hModule, "AVIStreamOpenFromFileW");
	O_AVIStreamRead = GetProcAddress(g_hModule, "AVIStreamRead");
	O_AVIStreamReadData = GetProcAddress(g_hModule, "AVIStreamReadData");
	O_AVIStreamReadFormat = GetProcAddress(g_hModule, "AVIStreamReadFormat");
	O_AVIStreamRelease = GetProcAddress(g_hModule, "AVIStreamRelease");
	O_AVIStreamSampleToTime = GetProcAddress(g_hModule, "AVIStreamSampleToTime");
	O_AVIStreamSetFormat = GetProcAddress(g_hModule, "AVIStreamSetFormat");
	O_AVIStreamStart = GetProcAddress(g_hModule, "AVIStreamStart");
	O_AVIStreamTimeToSample = GetProcAddress(g_hModule, "AVIStreamTimeToSample");
	O_AVIStreamWrite = GetProcAddress(g_hModule, "AVIStreamWrite");
	O_AVIStreamWriteData = GetProcAddress(g_hModule, "AVIStreamWriteData");
	O_CreateEditableStream = GetProcAddress(g_hModule, "CreateEditableStream");
	O_DllCanUnloadNow = GetProcAddress(g_hModule, "DllCanUnloadNow");
	O_DllGetClassObject = GetProcAddress(g_hModule, "DllGetClassObject");
	O_EditStreamClone = GetProcAddress(g_hModule, "EditStreamClone");
	O_EditStreamCopy = GetProcAddress(g_hModule, "EditStreamCopy");
	O_EditStreamCut = GetProcAddress(g_hModule, "EditStreamCut");
	O_EditStreamPaste = GetProcAddress(g_hModule, "EditStreamPaste");
	O_EditStreamSetInfo = GetProcAddress(g_hModule, "EditStreamSetInfo");
	O_EditStreamSetInfoA = GetProcAddress(g_hModule, "EditStreamSetInfoA");
	O_EditStreamSetInfoW = GetProcAddress(g_hModule, "EditStreamSetInfoW");
	O_EditStreamSetName = GetProcAddress(g_hModule, "EditStreamSetName");
	O_EditStreamSetNameA = GetProcAddress(g_hModule, "EditStreamSetNameA");
	O_EditStreamSetNameW = GetProcAddress(g_hModule, "EditStreamSetNameW");
	O_IID_IAVIEditStream = GetProcAddress(g_hModule, "IID_IAVIEditStream");
	O_IID_IAVIFile = GetProcAddress(g_hModule, "IID_IAVIFile");
	O_IID_IAVIStream = GetProcAddress(g_hModule, "IID_IAVIStream");
	O_IID_IGetFrame = GetProcAddress(g_hModule, "IID_IGetFrame");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		// Load original DLL
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\avifil32.dll");
		g_hModule = LoadLibraryA(path);
		if (!g_hModule) return FALSE;
		
		// Retrieve exported function pointers
		PopulateAddresses();
		
		// Call entry point
		start();
		return TRUE;
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
		FreeLibrary(g_hModule);
		return TRUE;
	}
}
