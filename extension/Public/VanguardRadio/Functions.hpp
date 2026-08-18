// This file is released into the public domain. See COPYING.
// Functions.hpp : parses and forwards function calls from SQF

#include <string>
#include <string_view>
#include <vector>

#include "VanguardRadio/Types.hpp"

namespace VanguardRadio {
    Error parseFunctionCall(
        std::string_view functionName,
        const std::vector<std::string_view>& arguments,
        std::string* output
    );

    Error parseVectorArgument(std::string_view argument, Vector3D* outVector);

    const std::string functionNameTest = "test";
    const size_t numArgsTest = 0;
    Error test(std::string* output);
};
