# DQM3SaveEditor Test Runner
# PowerShell script to run unit tests

Write-Host "Running DQM3SaveEditor Tests..." -ForegroundColor Green
Write-Host ""

# Check if .NET is installed
try {
    $dotnetVersion = dotnet --version
    Write-Host "Using .NET SDK version: $dotnetVersion" -ForegroundColor Cyan
}
catch {
    Write-Host "Error: .NET SDK is not installed or not in PATH" -ForegroundColor Red
    Write-Host "Please install .NET 8.0 SDK from https://dotnet.microsoft.com/download" -ForegroundColor Yellow
    Read-Host "Press Enter to exit"
    exit 1
}

# Build the test project
Write-Host "Building test project..." -ForegroundColor Cyan
$buildResult = dotnet build DQM3SaveEditor.Tests.csproj
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to build test project" -ForegroundColor Red
    Read-Host "Press Enter to exit"
    exit 1
}

# Run the tests
Write-Host ""
Write-Host "Running tests..." -ForegroundColor Cyan
$testResult = dotnet test DQM3SaveEditor.Tests.csproj --verbosity normal --logger "console;verbosity=normal"

# Display results summary
Write-Host ""
if ($LASTEXITCODE -eq 0) {
    Write-Host "All tests passed! ✓" -ForegroundColor Green
} else {
    Write-Host "Some tests failed! ✗" -ForegroundColor Red
}

Write-Host ""
Write-Host "Test run completed." -ForegroundColor Cyan
Read-Host "Press Enter to exit" 