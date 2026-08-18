# This file is released into the public domain. See COPYING.

cmake_minimum_required(VERSION 3.24)
project(VanguardRadio VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# We have to put the libraries in the top-level source directory, otherwise HEMTT won't put them in the top-level
# directory of the mod, which is expected by Arma 3.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(extensions/VanguardRadioIPC)
