# CMakeLists.txt 

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable (BinarySearchAlgorithm ${SOURCES} ${HEADERS})

target_include_directories(BinarySearchAlgorithm PRIVATE include)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BinarySearchAlgorithm PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(BinarySearchAlgorithm PROPERTIES OUTPUT_NAME "BinarySearchAlgorithm")
