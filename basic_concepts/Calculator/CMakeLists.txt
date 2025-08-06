file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable (Calculator ${SOURCES} ${HEADERS})

target_include_directories(Calculator PRIVATE include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Calculator PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(Calculator PROPERTIES OUTPUT_NAME "Calculator")