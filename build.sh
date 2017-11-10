#!/bin/sh

export A4INCDIR=$(ALLEGRO_DIR)/include
g++ -Wall -g -o bin\Eagle4Demo.exe -DALLEGRO_STATICLINK -I include $(A4INCDIR) src\TestPrograms\Eagle4WidgetDemo.cpp -L lib $(A4LNKDIR) -leagle4-debug -lalleg
