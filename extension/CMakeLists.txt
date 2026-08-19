# This file is released into the public domain. See COPYING.

include_directories(Public)

add_library(VanguardRadio MODULE Private/Extern.cpp Private/Functions.cpp)

set_target_properties(VanguardRadio PROPERTIES PREFIX "")
if(${VGR_BUILD_LINUX})
    set_target_properties(VanguardRadio PROPERTIES SUFFIX ".so")
elseif(${VGR_BUILD_WINDOWS})
    set_target_properties(VanguardRadio PROPERTIES SUFFIX ".dll")
    target_link_libraries(VanguardRadio -static)
elseif(${VGR_BUILD_WINDOWS64})
    set_target_properties(VanguardRadio PROPERTIES SUFFIX "_x64.dll")
    target_link_libraries(VanguardRadio -static)
endif()
