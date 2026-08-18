#!/bin/sh
# This file is released into the public domain. See COPYING.

cd $0/..

build_extension() {
    cmake --build build/linux
    cmake --build build/windows
    cmake --build build/windows64
}

case $1 in
    "dev" )
        build_extension
        hemtt dev
        ;;
    "release" )
        build_extension
        hemtt build
        ;;
    * )
        echo "Usage: build.sh [dev, release]"
        ;;
esac
