#!/bin/sh
# This file is released into the public domain. See COPYING.

cd $0/..

rm -r build/linux
rm -r build/windows
rm -r build/windows64

cmake -B build/linux -DCMAKE_TOOLCHAIN_FILE=toolchains/LinuxToolchain.cmake
cmake -B build/windows -DCMAKE_TOOLCHAIN_FILE=toolchains/WindowsToolchain.cmake
cmake -B build/windows64 -DCMAKE_TOOLCHAIN_FILE=toolchains/Windows64Toolchain.cmake

echo 'Setup done, run "cmake --build build/linux", "cmake --build build/windows", or "cmake --build build/windows64"'
