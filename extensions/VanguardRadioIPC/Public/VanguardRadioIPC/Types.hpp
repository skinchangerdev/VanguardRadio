// This file is released into the public domain. See COPYING.
// Error.hpp : defines error values for function returns.

#include <array>

namespace VanguardRadioIPC {
    using Vector3D = std::array<float, 3>;

    enum class Error {
        None = 0,
        FunctionName = 1,
        ArgumentsNumber = 2,
        Vector3DSyntax = 3
    };
};
