cmake_minimum_required(VERSION 3.30.0)

project(fridayc LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(EXTERNAL_BASE_DIR C:/Dev/C++)

# Find llvm package
find_package(LLVM REQUIRED CONFIG)

# Find antlr include dir
find_path(ANTLR4_INCLUDE_DIR 
NAMES antlr4-runtime.h
PATH_SUFFIXES antlr4-runtime
)

# Find raylib
find_package(raylib REQUIRED)

if(raylib_FOUND)
  message(STATUS "Raylib found at ${raylib_DIR}")
else()
  message(FATAL_ERROR "Raylib could not be located. Please install raylib")
endif()
  

if(ANTLR4_INCLUDE_DIR)
  message(STATUS "Antlr4 include directory found at: ${ANTLR4_INCLUDE_DIR}")
else()
  message(FATAL_ERROR "Antlr4 include directory could not be located. Please install antlr4 runtime")
endif()

# Find antlr runtime lib
find_library(ANTLR4_LIBRARY 
  NAMES antlr4-runtime antlr4-runtime_static
)

if(ANTLR4_LIBRARY)
  message(STATUS "Antlr4 runtime library directory found at: ${ANTLR4_INCLUDE_DIR}")
else()
  message(FATAL_ERROR "Antlr4 runtime library directory could not be located. Please install antlr4 runtime")
endif()

# Find antlr runtime jar
set(ANTLR_JAR "${CMAKE_CURRENT_SOURCE_DIR}/bin/antlr.jar")

if(ANTLR_JAR)
  message(STATUS "Antlr4 tool binary executable found at: ${ANTLR_JAR}")
else()
  message(FATAL_ERROR "Antlr4 tool binary executable could not be located. Please install antlr4 binary executable tool")
endif()


# Find java runtime environment
find_program(JAVA_EXECUTABLE NAMES java)

if(JAVA_EXECUTABLE)
  message(STATUS "Java executable binary found at: ${JAVA_EXECUTABLE}")
else()
  message(FATAL_ERROR "Java executable binary could not be located. Please install java.")
endif()


set(ANTLR_GEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/generated)

set(ANTLR_LEXER_SOURCES
  ${ANTLR_GEN_DIR}/FridayScanner.cpp
)

set(ANTLR_PARSER_SOURCES
  ${ANTLR_GEN_DIR}/FridayParser.cpp
  ${ANTLR_GEN_DIR}/FridayParserBaseVisitor.cpp
  ${ANTLR_GEN_DIR}/FridayParserVisitor.cpp
  ${ANTLR_GEN_DIR}/FridayParserBaseListener.cpp
  ${ANTLR_GEN_DIR}/FridayParserListener.cpp
)

set(ANTLR_SOURCES 
  ${ANTLR_LEXER_SOURCES}
  ${ANTLR_PARSER_SOURCES}
)

set(PARSER_GRAMMAR_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/FridayParser.g4)
set(LEXER_GRAMMAR_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/FridayScanner.g4)


add_custom_command(
  OUTPUT ${ANTLR_LEXER_SOURCES}
  COMMAND java -jar "${ANTLR_JAR}" -o "${ANTLR_GEN_DIR}" -Dlanguage=Cpp "${LEXER_GRAMMAR_FILE}"
  DEPENDS ${LEXER_GRAMMAR_FILE}
  COMMENT "Building Lexer Grammar ${LEXER_GRAMMAR_FILE}"
)

add_custom_command(
  OUTPUT ${ANTLR_PARSER_SOURCES}
  COMMAND java -jar "${ANTLR_JAR}" -o "${ANTLR_GEN_DIR}" -Dlanguage=Cpp -package friday -visitor -listener "${PARSER_GRAMMAR_FILE}"
  DEPENDS ${PARSER_GRAMMAR_FILE} ${LEXER_SOURCES}
  COMMENT "Building Parser Grammar ${PARSER_GRAMMAR_FILE}"
)


add_library(friday_api)

target_include_directories(friday_api PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${LLVM_INCLUDE_DIRS}
  ${ANTLR_GEN_DIR}
  ${ANTLR4_INCLUDE_DIR}
  ${EXTERNAL_BASE_DIR}/cpp/include
  ${EXTERNAL_BASE_DIR}/graphlib/include
  ${EXTERNAL_BASE_DIR}/iolib/include
)

target_link_directories(friday_api PUBLIC
  ${EXTERNAL_BASE_DIR}/cpp/lib
  ${EXTERNAL_BASE_DIR}/graphlib/lib
  ${EXTERNAL_BASE_DIR}/iolib/lib
)

target_link_libraries(friday_api PUBLIC
  stdc++exp
  antlr4-runtime
  LLVM-22
  ${ANTLR_LIBRARY}
  cpp
  graphlib
  iolib
  raylib
  opengl32
  gdi32
  winmm
)

target_compile_options(friday_api PUBLIC
  "-O0"
  "-Wall"
  "-Wextra"
  "-Wpedantic"
)

target_precompile_headers(friday_api PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/fridayc/Common.hpp
)

file(GLOB STATIC_ANALYZER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/analyzer/*.cpp)
file(GLOB CODE_GENERATOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/generator/*.cpp)
file(GLOB CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.cpp)
file(GLOB CLIENT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/client/*.cpp)
file(GLOB RUNTIME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cpp)

target_sources(friday_api PUBLIC 
  ${CORE_SOURCES}
  ${STATIC_ANALYZER_SOURCES}
  ${CODE_GENERATOR_SOURCES}
  ${ANTLR_SOURCES}
)

add_executable(fridayc ${CLIENT_SOURCES})
target_link_directories(fridayc PUBLIC lib)
target_link_libraries(fridayc PUBLIC friday_api)


add_library(friday-runtime ${RUNTIME_SOURCES})