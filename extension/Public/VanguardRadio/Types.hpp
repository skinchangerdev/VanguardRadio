// This file is released into the public domain. See COPYING.
// Error.hpp : defines error values for function returns.

#pragma once

#include <array>

namespace VanguardRadio {
    using Vector3D = std::array<float, 3>;

    enum class Error {
        // No error, all good
        None = 0,
        // SQF called with an unknown function name
        FunctionName = 1,
        // SQF called with an incorrect number of arguments
        ArgumentsNumber = 2,
        // SQF called with an incorrect/unparseable syntax for a Vector3D argument
        Vector3DSyntax = 3,
        // SQF tried to initialize MumbleLink when it was already initialized
        AlreadyInitialized = 4,
        // SQF tried to initialize MumbleLink, but some failure was encountered
        FailedInitialization = 5,
        // SQF tried to communicate with MumbleLink when it was yet to be initialized
        NotInitialized = 6
    };
};
