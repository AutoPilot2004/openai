@echo OFF
@cd /d "%~dp0"
@mkdir build
@cd build
cmake ..
cmake --build .
PAUSE