REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOAD_DIR=%USERPROFILE%\Downloads
set DOWNLOAD_DIR_LINUX=%DOWNLOAD_DIR:\=/%
SET PATH=%DOWNLOAD_DIR%\PortableGit\bin;%DOWNLOAD_DIR%\mingw64-posix;%DOWNLOAD_DIR%\mingw64-posix\bin;%DOWNLOAD_DIR%\cmake-3.22.0-rc1-windows-x86_64\bin;%PATH%

cmake.exe -G"MinGW Makefiles" -Dlibcurl_ROOT="P:/Downloads/cpp-libraries/curl-7_81_0" -B./build

cd build
:rebuild_and_startapp
mingw32-make.exe
pause
REM GOTO rebuild_and_startapp
