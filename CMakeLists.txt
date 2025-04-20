cmake_minimum_required(VERSION 3.14)

project(SimpleWin32Client 
        VERSION 1.0.0
        LANGUAGES C)

# set(CMAKE_C_STANDARD 23)
# set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    message(STATUS "Building on Windows...")
    set_target_properties(Win32App PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
    )

elseif(UNIX)
    message(STATUS "Building on a Unix-like system ...")
    message(STATUS "Checking for MinGW-w64 cross-compiler ...")

    # Check if the MinGW-w64 cross-compiler is available
    find_program(MINGW_COMPILER NAMES x86_64-w64-mingw32-gcc)
    
    if(MINGW_COMPILER)
        message(STATUS "MinGW-w64 found: ${MINGW_COMPILER}.")
        message(STATUS "Configuring CMake for cross-compilation ...")

        set(CMAKE_SYSTEM_NAME Windows)
        set(CMAKE_SYSTEM_PROCESSOR x86_64)

        # Specify the path to MinGW-w64 cross compiler
        set(CMAKE_C_COMPILER ${MINGW_COMPILER})
        set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
        set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

        # where is the target environment
        set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)
        # search for programs in the build host directories
        set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
        # for libraries and headers in the target directories
        set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
        set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
        
    else()
        message(FATAL_ERROR "MinGW-w64 cross-compiler not found. Please install it for cross-compilation. See: mingw-w64.org")
    endif()
else()
    message(FATAL_ERROR "Unsupported host platform detected!")
endif()

file(GLOB_RECURSE WIN32_CLIENT_APPLICATION_SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(
    Win32App
    ${WIN32_CLIENT_APPLICATION_SOURCES}
)



# target_link_libraries(Win32App PRIVATE user32.lib gdi32.lib kernel32.lib)
target_link_libraries(Win32App PRIVATE user32 gdi32 kernel32)
