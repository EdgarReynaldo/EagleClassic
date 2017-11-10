g++ -Wall -g -o bin\Eagle4Demo.exe -DALLEGRO_STATICLINK -I include %A4INCDIR% src\TestPrograms\Eagle4WidgetDemo.cpp -L lib %A4LNKDIR% -leagle4-debug-static -lalleg-debug-static %A4STATICLIBS%

g++ -Wall -g -o bin\Eagle4Animation.exe -DALLEGRO_STATICLINK -I include %A4INCDIR% src\TestPrograms\AnimationTest.cpp -L lib %A4LNKDIR% -leagle4-debug-static -lalleg-debug-static %A4STATICLIBS%


