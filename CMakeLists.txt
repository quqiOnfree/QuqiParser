﻿cmake_minimum_required(VERSION 3.8)

project(JsonParser)

#import files
file(GLOB CPP_FILES
	"${PROJECT_SOURCE_DIR}/JsonParser/Json.cpp"
	"${PROJECT_SOURCE_DIR}/JsonParser/Json.h"
)

#addLibrary JsonParser
add_library(${PROJECT_NAME} ${CPP_FILES})

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_20)

if (MSVC)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /O2 /Ot /GL /Gy")

	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif(MSVC)