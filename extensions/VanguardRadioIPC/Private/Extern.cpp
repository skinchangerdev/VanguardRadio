// This file is released into the public domain. See COPYING.
// Extern.cpp : defines C ABI which Arma 3 uses

#include <cstring>
#include <string>

#include "VanguardRadioIPC/Functions.hpp"

extern "C" {
    __attribute__((dllexport)) void RVExtensionVersion(char* output, unsigned int outputSize);

    __attribute__((dllexport)) void RVExtension(char* output, unsigned int outputSize, const char* functionName);

    __attribute__((dllexport)) int RVExtensionArgs(
        char* output,
        unsigned int outputSize,
        const char* functionName,
        const char** arguments,
        unsigned int argumentsSize
    );
}

void RVExtensionVersion(char* output, unsigned int outputSize) {
    const char extensionName[] = "VanguardRadioIPC v0.1.0";
    std::strncpy(output, extensionName, outputSize - 1);
}

void RVExtension(char* output, unsigned int outputSize, const char* functionName) {
    std::string safeOutput = {};
    std::vector<std::string_view> argumentsViews = {};

    VanguardRadioIPC::parseFunctionCall(functionName, argumentsViews, &safeOutput);

    safeOutput.copy(output, outputSize);
}

int RVExtensionArgs(
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

    VanguardRadioIPC::parseFunctionCall(functionName, argumentViews, &safeOutput);

    safeOutput.copy(output, outputSize);
    // I'm not quite sure what the return value does
    return 0;
}
