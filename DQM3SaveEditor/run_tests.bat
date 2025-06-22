@echo off
echo Running DQM3SaveEditor Tests...
echo.

REM Check if .NET is installed
dotnet --version >nul 2>&1
if errorlevel 1 (
    echo Error: .NET SDK is not installed or not in PATH
    echo Please install .NET 8.0 SDK from https://dotnet.microsoft.com/download
    pause
    exit /b 1
)

REM Build the test project
echo Building test project...
dotnet build DQM3SaveEditor.Tests.csproj
if errorlevel 1 (
    echo Error: Failed to build test project
    pause
    exit /b 1
)

REM Run the tests
echo.
echo Running tests...
dotnet test DQM3SaveEditor.Tests.csproj --verbosity normal

echo.
echo Tests completed.
pause 