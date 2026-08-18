// This file is released into the public domain. See COPYING.

#include "VanguardRadioIPC/Functions.hpp"

#include <string>

using namespace VanguardRadioIPC;

Error VanguardRadioIPC::parseFunctionCall(
    std::string_view functionName,
    const std::vector<std::string_view>& arguments,
    std::string* output
) {
    if (functionName == functionNameTest) {
        if (arguments.size() != numArgsTest) {
            return Error::ArgumentsNumber;
        }
        return test(output);
    } else {
        return Error::FunctionName;
    }
}

Error VanguardRadioIPC::parseVectorArgument(std::string_view argument, Vector3D* outVector) {
    std::string numberChars = "1234567890-";
    size_t searchStart = 0;

    for (int index = 0; index < outVector->size(); index++) {
        size_t numberStart = argument.find_first_of(numberChars, searchStart);
        if (numberStart == std::string_view::npos) {
            return Error::Vector3DSyntax;
        }

        std::string numberString = std::string(argument.substr(numberStart));

        outVector->at(index) = std::stof(numberString, &searchStart);
    }

    return Error::None;
}

Error VanguardRadioIPC::test(std::string* output) {
    *output = "Hello, Volker!";
    return Error::None;
}
