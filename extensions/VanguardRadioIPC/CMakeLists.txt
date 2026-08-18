# This file is released into the public domain. See COPYING.

include_directories(Public)

add_library(VanguardRadioIPC MODULE Private/Extern.cpp Private/Functions.cpp)

set_target_properties(VanguardRadioIPC PROPERTIES PREFIX "")

if(${VGR_BUILD_LINUX})
    set_target_properties(VanguardRadioIPC PROPERTIES SUFFIX ".so")
elseif(${VGR_BUILD_WINDOWS})
    set_target_properties(VanguardRadioIPC PROPERTIES SUFFIX ".dll")
elseif(${VGR_BUILD_WINDOWS64})
    set_target_properties(VanguardRadioIPC PROPERTIES SUFFIX "_x64.dll")
endif()
