cmake_minimum_required(VERSION 3.8)

project(QuqiParser)

add_library(QuqiParser "src/Ini.cpp" "src/Json.cpp")
target_include_directories(QuqiParser PUBLIC include/)

target_include_directories(QuqiParser  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/QuqiParser>)

install(TARGETS 
	QuqiParser
	EXPORT QuqiParser
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib)

include(CMakePackageConfigHelpers)

configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/QuqiParserConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/QuqiParserConfig.cmake
        INSTALL_DESTINATION lib/cmake
        )

add_executable (test "test/test.cpp")
target_link_libraries(test PUBLIC QuqiParser)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QuqiParser PROPERTY CXX_STANDARD 20)
  set_property(TARGET test PROPERTY CXX_STANDARD 20)
endif()
