#!/bin/sh

# Build for Windows from Linux using mingw-w64
BUILD_TYPE=Debug
BUILD_DIR="build"
EXECUTABLE="Win32App.exe"

if [ ! -d "$BUILD_DIR" ]; then
    echo "$BUILD_DIR/ dir does not exist. Creating it..."
    mkdir "$BUILD_DIR"
fi

echo "cd $BUILD_DIR/"
cd "$BUILD_DIR"

echo "Running cmake .."
cmake ..

echo "Building with $BUILD_TYPE configuration..."
cmake --build . --config "$BUILD_TYPE"

if [ -f "$EXECUTABLE" ]; then
    echo "Launching executable..."
    wine "$EXECUTABLE"
    echo "Done."
else
    echo "Build Failed!"
fi
