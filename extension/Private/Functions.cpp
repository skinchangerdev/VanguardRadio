// This file is released into the public domain. See COPYING.

#include "VanguardRadio/Functions.hpp"

#include <string>

#include "VanguardRadio/Mumble.hpp"

using namespace VanguardRadio;

Error VanguardRadio::parseFunctionCall(
    std::string_view functionName,
    const std::vector<std::string_view>& arguments,
    std::string* output
) {
    // TODO: reduce code duplication here by representing functions exposed to SQF as objects
    if (functionName == functionNameTest) {
        if (arguments.size() != numArgsTest) {
            return Error::argumentsNumber;
        }
        return test(output);
    }
#if _WIN32
    else if (functionName == functionNameMumbleInit) {
        if (arguments.size() != numArgsMumbleInit) {
            return Error::argumentsNumber;
        }
        return mumbleInit();
    } else if (functionName == functionNameMumbleSessionUpdate) {
        if (arguments.size() != numArgsMumbleSessionUpdate) {
            return Error::argumentsNumber;
        }
        std::string context = std::string(arguments[0]);
        std::string identity = std::string(arguments[1]);
        return mumbleSessionUpdate(context, identity);
    }
#endif
    else {
        return Error::functionName;
    }
}

Error VanguardRadio::parseVectorArgument(std::string_view argument, Vector3D* outVector) {
    std::string numberChars = "1234567890-";
    size_t searchStart = 0;

    for (int index = 0; index < outVector->size(); index++) {
        size_t numberStart = argument.find_first_of(numberChars, searchStart);
        if (numberStart == std::string_view::npos) {
            return Error::vector3DSyntax;
        }

        std::string numberString = std::string(argument.substr(numberStart));

        outVector->at(index) = std::stof(numberString, &searchStart);
    }

    // We need to invert the X-axis, as Arma 3 uses right-handed coordinates but Mumble expects left-handed coordinates.
    outVector->at(0) = outVector->at(0) * -1.0;

    return Error::none;
}

Error VanguardRadio::test(std::string* output) {
    *output = "Hello, Volker!";
    return Error::none;
}
