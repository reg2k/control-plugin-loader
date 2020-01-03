shim MACRO fnName
    _&fnName& PROC
        EXTERN O_&fnName& : qword
        mov rax, O_&fnName&
        jmp rax
    _&fnName& ENDP
    PUBLIC _&fnName&
ENDM

.code
shim AVIBuildFilter
shim AVIBuildFilterA
shim AVIBuildFilterW
shim AVIClearClipboard
shim AVIFileAddRef
shim AVIFileCreateStream
shim AVIFileCreateStreamA
shim AVIFileCreateStreamW
shim AVIFileEndRecord
shim AVIFileExit
shim AVIFileGetStream
shim AVIFileInfo
shim AVIFileInfoA
shim AVIFileInfoW
shim AVIFileInit
shim AVIFileOpen
shim AVIFileOpenA
shim AVIFileOpenW
shim AVIFileReadData
shim AVIFileRelease
shim AVIFileWriteData
shim AVIGetFromClipboard
shim AVIMakeCompressedStream
shim AVIMakeFileFromStreams
shim AVIMakeStreamFromClipboard
shim AVIPutFileOnClipboard
shim AVISave
shim AVISaveA
shim AVISaveOptions
shim AVISaveOptionsFree
shim AVISaveV
shim AVISaveVA
shim AVISaveVW
shim AVISaveW
shim AVIStreamAddRef
shim AVIStreamBeginStreaming
shim AVIStreamCreate
shim AVIStreamEndStreaming
shim AVIStreamFindSample
shim AVIStreamGetFrame
shim AVIStreamGetFrameClose
shim AVIStreamGetFrameOpen
shim AVIStreamInfo
shim AVIStreamInfoA
shim AVIStreamInfoW
shim AVIStreamLength
shim AVIStreamOpenFromFile
shim AVIStreamOpenFromFileA
shim AVIStreamOpenFromFileW
shim AVIStreamRead
shim AVIStreamReadData
shim AVIStreamReadFormat
shim AVIStreamRelease
shim AVIStreamSampleToTime
shim AVIStreamSetFormat
shim AVIStreamStart
shim AVIStreamTimeToSample
shim AVIStreamWrite
shim AVIStreamWriteData
shim CreateEditableStream
shim DllCanUnloadNow
shim DllGetClassObject
shim EditStreamClone
shim EditStreamCopy
shim EditStreamCut
shim EditStreamPaste
shim EditStreamSetInfo
shim EditStreamSetInfoA
shim EditStreamSetInfoW
shim EditStreamSetName
shim EditStreamSetNameA
shim EditStreamSetNameW
shim IID_IAVIEditStream
shim IID_IAVIFile
shim IID_IAVIStream
shim IID_IGetFrame

END
