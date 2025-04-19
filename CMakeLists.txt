cmake_minimum_required(VERSION 3.14)

project(SimpleWin32Client 
        VERSION 1.0.0
        LANGUAGES C)

file(GLOB_RECURSE WIN32_CLIENT_APPLICATION_SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(
    Win32App
    ${WIN32_CLIENT_APPLICATION_SOURCES}
)

set_target_properties(Win32App PROPERTIES
    LINK_FLAGS "/SUBSYSTEM:WINDOWS"
)

target_link_libraries(Win32App PRIVATE user32.lib gdi32.lib kernel32.lib)
