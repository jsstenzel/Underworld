:: Run with the Developer Command Prompt for VS
cd ..
set COREFILES=engine\room.cpp engine\state.cpp engine\parser.cpp
set SRCFILES=src\main.cpp src\token.cpp src\game_parser.cpp
set INCLUDES="."
set EXENAME=Underworld
cls

cmd /c "cl /I%INCLUDES% /EHsc %COREFILES% %SRCFILES% /link /out:%EXENAME%.exe" 

move .\*.obj .\vs-build
move .\%EXENAME%.exe .\vs-build

cd vs-build
