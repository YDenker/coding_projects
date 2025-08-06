# CMakeLists.txt 

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable (BasicSortingAlgorithms ${SOURCES} ${HEADERS})

target_include_directories(BasicSortingAlgorithms PRIVATE include)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BasicSortingAlgorithms PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(BasicSortingAlgorithms PROPERTIES OUTPUT_NAME "BasicSortingAlgorithms")
