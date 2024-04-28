# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\VehicleMonitoringSytem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\VehicleMonitoringSytem_autogen.dir\\ParseCache.txt"
  "Service\\CMakeFiles\\Service_autogen.dir\\AutogenUsed.txt"
  "Service\\CMakeFiles\\Service_autogen.dir\\ParseCache.txt"
  "Service\\Service_autogen"
  "VehicleMonitoringSytem_autogen"
  "googlemock\\CMakeFiles\\gmock_autogen.dir\\AutogenUsed.txt"
  "googlemock\\CMakeFiles\\gmock_autogen.dir\\ParseCache.txt"
  "googlemock\\CMakeFiles\\gmock_main_autogen.dir\\AutogenUsed.txt"
  "googlemock\\CMakeFiles\\gmock_main_autogen.dir\\ParseCache.txt"
  "googlemock\\gmock_autogen"
  "googlemock\\gmock_main_autogen"
  "googletest\\CMakeFiles\\gtest_autogen.dir\\AutogenUsed.txt"
  "googletest\\CMakeFiles\\gtest_autogen.dir\\ParseCache.txt"
  "googletest\\CMakeFiles\\gtest_main_autogen.dir\\AutogenUsed.txt"
  "googletest\\CMakeFiles\\gtest_main_autogen.dir\\ParseCache.txt"
  "googletest\\gtest_autogen"
  "googletest\\gtest_main_autogen"
  )
endif()
