file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable (HelloCMakeWorld ${SOURCES} ${HEADERS})

target_include_directories(HelloCMakeWorld PRIVATE include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HelloCMakeWorld PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(HelloCMakeWorld PROPERTIES OUTPUT_NAME "HelloCMakeWorld")