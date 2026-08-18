# This file is released into the public domain. See COPYING.

include_directories(Public)

add_library(VanguardRadioIPC MODULE Private/Extern.cpp Private/Functions.cpp)

set_target_properties(VanguardRadioIPC PROPERTIES PREFIX "")
