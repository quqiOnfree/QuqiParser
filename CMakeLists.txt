cmake_minimum_required(VERSION 3.8)

project(QuqiParser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(QuqiParser "src/Ini.cpp" "src/Json.cpp")
target_include_directories(QuqiParser PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_include_directories(QuqiParser INTERFACE
    $<INSTALL_INTERFACE:include/QuqiParser>)

# test
add_executable(test "test/test.cpp")
target_link_libraries(test PRIVATE QuqiParser)

# install
install(TARGETS QuqiParser
    EXPORT quqiparser-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin)

install(FILES
    "include/QuqiParser/Ini.h"
    "include/QuqiParser/Json.h"
    DESTINATION include/QuqiParser
    )

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/quqiparser-config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/quqiparser-config.cmake"
    INSTALL_DESTINATION share/QuqiParser)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/quqiparser-config.cmake"
    DESTINATION share/QuqiParser)

install(EXPORT quqiparser-targets
    FILE quqiparser-targets.cmake
    NAMESPACE QuqiParser::
    DESTINATION share/QuqiParser)
