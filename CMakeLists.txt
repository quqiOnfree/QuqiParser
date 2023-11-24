cmake_minimum_required(VERSION 3.8)

project(QuqiParser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(QuqiParser "src/Ini.cpp" "src/Json.cpp")
target_include_directories(QuqiParser PUBLIC include/)
target_link_directories(QuqiParser INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (test "test/test.cpp")
target_link_libraries(test PUBLIC QuqiParser)
