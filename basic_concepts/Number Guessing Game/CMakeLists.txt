# CMakeLists.txt 

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable (NumberGuessingGame ${SOURCES} ${HEADERS})

target_include_directories(NumberGuessingGame PRIVATE include)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NumberGuessingGame PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(NumberGuessingGame PROPERTIES OUTPUT_NAME "NumberGuessingGame")
