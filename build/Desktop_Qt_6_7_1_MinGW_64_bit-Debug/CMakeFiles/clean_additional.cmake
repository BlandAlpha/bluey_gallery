# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "FluentUI\\CMakeFiles\\fluentuiplugin_autogen.dir\\AutogenUsed.txt"
  "FluentUI\\CMakeFiles\\fluentuiplugin_autogen.dir\\ParseCache.txt"
  "FluentUI\\fluentuiplugin_autogen"
  "src\\CMakeFiles\\bluey_gallery_autogen.dir\\AutogenUsed.txt"
  "src\\CMakeFiles\\bluey_gallery_autogen.dir\\ParseCache.txt"
  "src\\bluey_gallery_autogen"
  "src\\rcc_object_qml_autogen"
  )
endif()
