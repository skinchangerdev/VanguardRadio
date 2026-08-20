// This file is released into the public domain. See COPYING.

// A lot of this code is based on code from
// https://www.mumble.info/documentation/developer/positional-audio/link-plugin/, which is also in the public domain.

#include "VanguardRadio/Mumble.hpp"

#if _WIN32
    #include <codecvt>
    #include <cstring>
    #include <cwchar>
    #include <locale>
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

    // Undocumented by Mumble, unknown usage
    wchar_t name[256];

    float cameraPosition[3];
    float cameraForwards[3];
    float cameraUpwards[3];

    wchar_t identity[256];

    UINT32 contextLength;
    unsigned char context[256];
    // Undocumented by Mumble, unknown usage
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

    void* sharedMemoryMap = MapViewOfFile(sharedMemoryHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MumbleSharedMemory));
    if (sharedMemoryMap == NULL) {
        CloseHandle(sharedMemoryHandle);
        return Error::failedInitialization;
    }

    sharedMemory = (MumbleSharedMemory*)sharedMemoryMap;
    return Error::none;
}

Error VanguardRadio::mumbleSessionUpdate(const std::string& context, const std::string& identity) {
    if (sharedMemory == nullptr) {
        return Error::notInitialized;
    }

    const size_t contextMaxLength = 256;
    const size_t identityMaxLength = 256;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    // We use strncpy (and later wcsncpy) to ensure excess characters in the shared memory are null
    char* contextPtr = (char*)sharedMemory->context;
    std::strncpy(contextPtr, context.c_str(), contextMaxLength);
    sharedMemory->contextLength = std::min(context.length(), contextMaxLength);

    std::wstring wideIdentity = converter.from_bytes(identity);
    wchar_t* identityPtr = (wchar_t*)sharedMemory->identity;
    std::wcsncpy(identityPtr, wideIdentity.c_str(), identityMaxLength);

    return Error::none;
}

Error VanguardRadio::mumbleFrameUpdate(const Vector3D& position, const Vector3D& forwards, const Vector3D& upwards) {
    if (sharedMemory == nullptr) {
        return Error::notInitialized;
    }

    const size_t vectorSize = sizeof(float[3]);
    std::memcpy(&sharedMemory->avatarPosition, position.data(), vectorSize);
    std::memcpy(&sharedMemory->cameraPosition, position.data(), vectorSize);
    std::memcpy(&sharedMemory->avatarForwards, forwards.data(), vectorSize);
    std::memcpy(&sharedMemory->cameraForwards, forwards.data(), vectorSize);
    std::memcpy(&sharedMemory->avatarUpwards, upwards.data(), vectorSize);
    std::memcpy(&sharedMemory->cameraUpwards, upwards.data(), vectorSize);

    return Error::none;
}

void appendVectorToOutput(std::string vectorName, const float vector[3], std::string* output) {
    output->append(vectorName + ": ");
    output->append(std::to_string(vector[0]) + ", ");
    output->append(std::to_string(vector[1]) + ", ");
    output->append(std::to_string(vector[2]) + "\n");
}

Error VanguardRadio::mumbleDumpMemory(std::string* output) {
    if (sharedMemory == nullptr) {
        return Error::notInitialized;
    }

    std::string context = std::string((char*)sharedMemory->context);
    output->append("context: " + context + "\n");

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::string narrowIdentity = converter.to_bytes(sharedMemory->identity);
    output->append("identity: " + narrowIdentity + "\n");

    appendVectorToOutput("avatarPosition", sharedMemory->avatarPosition, output);
    appendVectorToOutput("cameraPosition", sharedMemory->cameraPosition, output);
    appendVectorToOutput("avatarForwards", sharedMemory->avatarForwards, output);
    appendVectorToOutput("cameraForwards", sharedMemory->cameraForwards, output);
    appendVectorToOutput("avatarUpwards", sharedMemory->avatarUpwards, output);
    appendVectorToOutput("cameraUpwards", sharedMemory->cameraUpwards, output);

    return Error::none;
}

#endif
