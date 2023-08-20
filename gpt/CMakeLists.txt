# CMakeList.txt : CMake project for gpt, include source and define
# project specific logic here.
#

file(GLOB_RECURSE SRC_FILES "*.cpp")

# Add source to this project's executable.
add_library(gpt ${SRC_FILES})

target_link_libraries(gpt PUBLIC cpr::cpr nlohmann_json::nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET gpt PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
