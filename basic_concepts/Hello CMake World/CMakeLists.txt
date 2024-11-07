# CMakeList.txt : CMake project for Hello CMake World, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget "src/main.cpp" "src/HelloCMakeWorld.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(CMakeTarget PROPERTIES OUTPUT_NAME "HelloCMakeWorld")