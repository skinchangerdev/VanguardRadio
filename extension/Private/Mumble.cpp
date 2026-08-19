// This file is released into the public domain. See COPYING.

// A lot of this code is based on code from
// https://www.mumble.info/documentation/developer/positional-audio/link-plugin/, which is also in the public domain.

#include "VanguardRadio/Mumble.hpp"

#if _WIN32
    #include <windows.h>
#endif

using namespace VanguardRadio;

#if _WIN32
struct MumbleSharedMemory {
    UINT32 uiVersion;
    DWORD uiTick;

    float avatarPosition[3];
    float avatarForwards[3];
    float avatarUpwards[3];

    wchar_t name[256];

    float cameraPosition[3];
    float cameraForwards[3];
    float cameraUpwards[3];

    wchar_t identity[256];

    UINT32 contextLength;
    unsigned char context[256];
    wchar_t description[2048];
};

MumbleSharedMemory* sharedMemory = nullptr;

Error VanguardRadio::mumbleInit() {
    if (sharedMemory != nullptr) {
        return Error::alreadyInitialized;
    }

    HANDLE sharedMemoryHandle = OpenFileMappingW(FILE_MAP_ALL_ACCESS, FALSE, L"MumbleLink");
    if (sharedMemoryHandle == NULL) {
        return Error::failedInitialization;
    }

    void* sharedMemoryMap = MapViewOfFile(sharedMemoryHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(sharedMemory));
    if (sharedMemoryMap == NULL) {
        CloseHandle(sharedMemoryHandle);
        return Error::failedInitialization;
    }

    sharedMemory = (MumbleSharedMemory*)sharedMemoryMap;
    return Error::none;
}

#endif
