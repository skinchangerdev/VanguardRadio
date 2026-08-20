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

    const std::string functionNameMumbleFrameUpdate = "mumbleFrameUpdate";
    const size_t numArgsMumbleFrameUpdate = 3;
    // Update MumbleLink position and direction information
    Error mumbleFrameUpdate(const Vector3D& position, const Vector3D& forwards, const Vector3D& upwards);
#endif
};
