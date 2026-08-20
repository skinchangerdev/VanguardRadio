// This file is released into the public domain. See COPYING.
// Extern.cpp : defines C ABI which Arma 3 uses

#include <cstdint>
#include <cstring>
#include <string>

#include "VanguardRadio/Functions.hpp"

#if _WIN32
    #define EXPORT_ATTRIBUTE __declspec(dllexport)
    #define CALLING_CONVENTION __stdcall
#else
    #define EXPORT_ATTRIBUTE
    #define CALLING_CONVENTION
#endif

enum FeatureFlags : uint64_t {
    contextArgumentsVoidPtr = 1 << 0,
    contextStackTrace = 1 << 1,
    contextNoDefaultCall = 1 << 2,
    argumentNoEscapeString = 1 << 3
};

extern "C" {
    EXPORT_ATTRIBUTE uint64_t RVExtensionFeatureFlags =
        FeatureFlags::contextNoDefaultCall | FeatureFlags::argumentNoEscapeString;

    EXPORT_ATTRIBUTE void CALLING_CONVENTION RVExtensionVersion(char* output, unsigned int outputSize);

    EXPORT_ATTRIBUTE void CALLING_CONVENTION
    RVExtension(char* output, unsigned int outputSize, const char* functionName);

    EXPORT_ATTRIBUTE int CALLING_CONVENTION RVExtensionArgs(
        char* output,
        unsigned int outputSize,
        const char* functionName,
        const char** arguments,
        unsigned int argumentsSize
    );
}

void CALLING_CONVENTION RVExtensionVersion(char* output, unsigned int outputSize) {
    const char extensionName[] = "VanguardRadio v0.1.0";
    std::strncpy(output, extensionName, outputSize - 1);
}

void CALLING_CONVENTION RVExtension(char* output, unsigned int outputSize, const char* functionName) {
    std::string safeOutput = "The non-arguments SQF callExtension syntax is unsupported.";
    safeOutput.copy(output, outputSize);
}

int CALLING_CONVENTION RVExtensionArgs(
    char* output,
    unsigned int outputSize,
    const char* functionName,
    const char** arguments,
    unsigned int argumentsSize
) {
    std::string safeOutput = {};
    std::vector<std::string_view> argumentViews = std::vector<std::string_view>(argumentsSize);
    for (int index = 0; index < argumentsSize; index++) {
        argumentViews[index] = std::string_view(arguments[index]);
    }

    VanguardRadio::Error error = VanguardRadio::parseFunctionCall(functionName, argumentViews, &safeOutput);

    safeOutput.copy(output, outputSize);
    return (int)error;
}

#undef EXPORT_ATTRIBUTE
#undef CALLING_CONVENTION
