@echo off
setlocal enabledelayedexpansion

set "INPUT_DIR=include"
set "OUTPUT_DIR=docs\doxygen"

if not exist "%OUTPUT_DIR%" (
  mkdir "%OUTPUT_DIR%"
)

where doxygen >nul 2>nul
if %errorlevel% neq 0 (
  echo [ERROR] Doxygen was not found in your PATH.
  echo Please install it from https://www.doxygen.nl/
  pause
  exit /b 1
)


echo Generating documentation from %INPUT_DIR%...
(
  echo PROJECT_NAME      = "fridayc API Reference"
  echo INPUT             = %INPUT_DIR%
  echo RECURSIVE         = YES
  echo OUTPUT_DIRECTORY  = %OUTPUT_DIR%
  echo GENERATE_HTML     = YES
  echo GENERATE_LATEX    = NO
  echo HTML_OUTPUT       = html
) | doxygen -
