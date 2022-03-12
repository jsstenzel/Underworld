:: Run with the Developer Command Prompt for VS
cd ..
set FILES=src\main.cpp src\token.cpp engine\room.cpp
set INCLUDES="."
cls

cmd /c "cl /I%INCLUDES% /EHsc %FILES% /link /out:Underworld.exe" 
cd vs-build
