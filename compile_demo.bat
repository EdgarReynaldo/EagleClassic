g++ -Wall -g -o bin\Eagle4Demo.exe -I include %A4INCDIR% src\TestPrograms\Eagle4WidgetDemo.cpp -L lib %A4LNKDIR% -leagle4-debug.dll -lalleg44-debug.dll

g++ -Wall -g -o bin\Eagle4Animation.exe -I include %A4INCDIR% src\TestPrograms\AnimationTest.cpp -L lib %A4LNKDIR% -leagle4-debug.dll -lalleg44-debug.dll
