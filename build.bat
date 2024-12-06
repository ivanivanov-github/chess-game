@echo off

if not exist "build" (
    mkdir build
) else (
    rmdir /s /q build
    mkdir build
)

cd build

cmake ..

if not errorlevel 1 (
    echo Building the project...
    cmake --build .
) else (
    echo Error during configuration. Exiting.
    exit /b 1
)

cd Debug

if exist "ChessGame.exe" (
    echo Running the program...
    ChessGame.exe
) else (
    echo Build failed. Exiting.
    exit /b 1
)

cd ../..