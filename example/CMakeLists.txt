add_executable(example main.cpp)
target_include_directories(example PRIVATE ..)
target_link_libraries(example PRIVATE gpt)