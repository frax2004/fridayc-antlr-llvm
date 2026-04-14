cmake_minimum_required(VERSION 3.30.0)

project(fridayc CXX)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)

set(MSYS C:/Dev/msys2/mingw64/)
set(LLVM ${MSYS})

file(GLOB SOURCES src/*.cpp)


add_executable(fridayc ${SOURCES})
target_include_directories(fridayc PRIVATE 
  include 
  include/api/parser 
  ${MSYS}/include/antlr4-runtime
  ${LLVM}/include
)

target_link_directories(fridayc PRIVATE 
  lib 
  ${MSYS}/bin 
  ${LLVM}/bin
)

target_link_libraries(fridayc PRIVATE 
  stdc++exp 
  antlr4-runtime 
  LLVM-22
)

target_compile_definitions(fridayc PRIVATE 
  _GLIBCXX_USE_CXX11_ABI=1 
  _FILE_OFFSET_BITS=64 
  __STDC_CONSTANT_MACROS 
  __STDC_FORMAT_MACROS 
  __STDC_LIMIT_MACROS
)

target_precompile_headers(fridayc PRIVATE 
  <bits/stdc++.h>
  <antlr4-runtime.h>
)

target_compile_options(fridayc PRIVATE 
  -O0
  -fconcepts-diagnostics-depth=4
  -funwind-tables
)
