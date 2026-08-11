cmake_minimum_required(VERSION 4.3)
project(cpp CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(TARGET cpp)

add_library(${TARGET}-static STATIC ${SOURCES})
target_include_directories(${TARGET}-static PUBLIC include)
target_link_libraries(${TARGET}-static PUBLIC stdc++exp)
set_target_properties(${TARGET}-static PROPERTIES OUTPUT_NAME ${TARGET})

add_library(${TARGET}-dynamic SHARED ${SOURCES})
target_include_directories(${TARGET}-dynamic PUBLIC include)
target_link_libraries(${TARGET}-dynamic PUBLIC stdc++exp)
set_target_properties(${TARGET}-dynamic PROPERTIES OUTPUT_NAME ${TARGET})
