@echo off
setlocal

set BUILD_TYPE=Debug

if not "%1"=="" (
    set BUILD_TYPE=%1
)

set BUILD_DIR=build

if not exist "%BUILD_DIR%" (
    echo "%BUILD_DIR%" does not exist. Creating it...
    mkdir "%BUILD_DIR%"
)

cd "%BUILD_DIR%"

echo Running cmake ..
cmake ..

echo Building the project with %BUILD_TYPE% configuration...
cmake --build . --config %BUILD_TYPE%

if exist "%BUILD_TYPE%\Win32App.exe" (
    echo Running the application...
    "%BUILD_TYPE%\Win32App.exe"
) else (
    echo Error: Win32App.exe not found. Build may have failed.
)

endlocal

