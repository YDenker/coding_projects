@echo off

REM Check if the user provided a directory and project name
if "%~1"=="" (
    echo Error: Please provide a target directory.
    exit /b 1
)
if "%~2"=="" (
    echo Error: Please provide a project name.
    exit /b 1
)

cd ..

REM Set the target path based on the given directory and project name
set "target_path=%~1\%~2"
set "given_name=%~2"
for /f "delims=" %%i in ('powershell -Command "$string = '%given_name%'; $string = $string -replace '\s',''; $string"') do set project_name=%%i

set "helper_file=helpers\cmake_template.txt"
set "cmake_file=%target_path%\CMakeLists.txt"

REM Create the project directory and subdirectories
mkdir "%target_path%"
mkdir "%target_path%\src"
mkdir "%target_path%\include"

REM Check if the helper file exists
if not exist "%helper_file%" (
    echo Error: cmake_template.txt file not found.
    exit /b 1
)

REM Copy Template File to new CMakeLists file
copy /Y "%helper_file%" "%cmake_file%"

REM Replaced all placeholders in the new CMakeLists file
powershell -Command "(Get-Content '%~dp0\..\%cmake_file%') -replace '_name_', '%project_name%' | Set-Content '%~dp0\..\%cmake_file%'"

REM Create main.cpp and main.h files in the src directory
echo // main.cpp > "%target_path%\src\main.cpp"
echo #include "main.h" >> "%target_path%\src\main.cpp"
echo int main() { return 0; } >> "%target_path%\src\main.cpp"

echo // main.h > "%target_path%\include\main.h"
echo #pragma once >> "%target_path%\include\main.h"

echo Project created successfully at %target_path%

echo add_subdirectory ("%~1/%~2") >> "CMakeLists.txt"