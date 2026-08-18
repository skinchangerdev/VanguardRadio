#!/bin/sh

cd $0/..

rm -r build/{linux,windows}
cmake -B build/linux -DCMAKE_TOOLCHAIN_FILE=toolchains/LinuxToolchain.cmake
cmake -B build/windows -DCMAKE_TOOLCHAIN_FILE=toolchains/WindowsToolchain.cmake

echo 'Setup done, run "cmake --build build/linux" or "cmake --build build/windows"'
