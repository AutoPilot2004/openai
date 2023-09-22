file(GLOB_RECURSE SRC_FILES "*.cpp")

add_library(gpt ${SRC_FILES})

target_link_libraries(gpt PRIVATE cpr::cpr nlohmann_json::nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET gpt PROPERTY CXX_STANDARD 20)
endif()