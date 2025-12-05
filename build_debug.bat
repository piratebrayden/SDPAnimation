@echo off
cd /d "%~dp0simulator_libraries"
mingw32-make clean
mingw32-make "CPPFLAGS=-MMD -MP -O0 -DOBJC_OLD_DISPATCH_PROTOTYPES -g"
