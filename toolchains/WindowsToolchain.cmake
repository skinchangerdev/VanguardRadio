# This file is released into the public domain. See COPYING.

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR X86)

set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)

set(CACHE{VGR_BUILD_WINDOWS} TYPE BOOL FORCE VALUE true)
