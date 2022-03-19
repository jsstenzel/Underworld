:: Run with the Developer Command Prompt for VS
cls
cd ..
set FILES=src\token.cpp
set INCLUDES="."
set ARGS="/EHsc /std:c++20"

cmd /c "cl /I%INCLUDES% %ARGS% %FILES% /link /out:TokenTest.exe" 
cd vs-build
