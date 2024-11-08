# CMakeLists.txt 

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable (TemperatureConverter ${SOURCES} ${HEADERS})

target_include_directories(TemperatureConverter PRIVATE include)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TemperatureConverter PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(TemperatureConverter PROPERTIES OUTPUT_NAME "TemperatureConverter")
