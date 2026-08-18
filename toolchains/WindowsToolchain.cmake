# This file is released into the public domain. See COPYING.

set(CMAKE_SYSTEM_NAME Windows)

set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

set(CACHE{VGR_BUILD_WINDOWS} TYPE BOOL FORCE VALUE true)
