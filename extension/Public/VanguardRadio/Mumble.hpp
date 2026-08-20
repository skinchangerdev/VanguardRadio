// This file is released into the public domain. See COPYING.
// Mumble.hpp : handles IPC with Mumble audio

#pragma once

#include <cstdint>
#include <string>

#include "VanguardRadio/Types.hpp"

namespace VanguardRadio {
#if _WIN32
    const std::string functionNameMumbleInit = "mumbleInit";
    const size_t numArgsMumbleInit = 0;
    // Initialize IPC with MumbleLink
    Error mumbleInit();

    const std::string functionNameMumbleSessionUpdate = "mumbleSessionUpdate";
    const size_t numArgsMumbleSessionUpdate = 2;
    // Update MumbleLink session information
    Error mumbleSessionUpdate(const std::string& context, const std::string& identity);
#endif
};
