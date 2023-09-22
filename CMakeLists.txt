cmake_minimum_required (VERSION 3.27.0)

set(ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW) 
endif()

project(openai)

find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

add_subdirectory(gpt)
add_subdirectory(example)