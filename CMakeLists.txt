cmake_minimum_required(VERSION 3.8)

project(QuqiParser)

file(
	GLOB FILE
	"${CMAKE_SOURCE_DIR}/*.h"
	"${CMAKE_SOURCE_DIR}/*.hpp"
	"${CMAKE_SOURCE_DIR}/*.cpp"
)

add_executable (${PROJECT_NAME} "${FILE}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)
endif()