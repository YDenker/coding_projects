# CMakeLists.txt 

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable (NumberChecker ${SOURCES} ${HEADERS} "include/main.h")

target_include_directories(NumberChecker PRIVATE include)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NumberChecker PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(NumberChecker PROPERTIES OUTPUT_NAME "NumberChecker")
