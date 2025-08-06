# CMakeLists.txt 

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")
file(GLOB GENERATORS "include/generators/*.h")

add_executable (RandomNumberGenerator ${SOURCES} ${HEADERS} ${GENERATORS})

target_include_directories(RandomNumberGenerator PRIVATE include)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RandomNumberGenerator PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(RandomNumberGenerator PROPERTIES OUTPUT_NAME "RandomNumberGenerator")
