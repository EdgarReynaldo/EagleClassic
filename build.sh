#!/bin/sh

if ($(ALLEGRO_DIR) == "")
   export ALLEGRO_DIR=/usr/local
export A4INCDIR=-I $(ALLEGRO_DIR)/include
export A4LNKDIR=-L $(ALLEGRO_DIR)/lib

g++ -Wall -g -o bin\Eagle4Demo -I include $(A4INCDIR) src\TestPrograms\Eagle4WidgetDemo.cpp -L lib $(A4LNKDIR) -leagle4-debug -lalleg

g++ -Wall -g -o bin\Eagle4Animation -I include $(A4INCDIR) src\TestPrograms\Animation.cpp -L lib $(A4LNKDIR) -leagle4-debug -lalleg
