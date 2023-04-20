cmake_minimum_required(VERSION 3.0)

project(ALGS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ALGS INTERFACE)

target_include_directories(ALGS INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/sorting>
        $<INSTALL_INTERFACE:sorting>
        )

target_include_directories(ALGS INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/searching>
        $<INSTALL_INTERFACE:searching>
        )

add_executable(main cli/main.cpp)

target_link_libraries(main ALGS)