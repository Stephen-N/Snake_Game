/*************************************************
**  File            :   main.cpp
**  Project         :   Snake
**  Author          :   Stephen Ndubueze
**  Start Date      :   05/16/2020
**  E-mail          :   sundubueze78@gmail.com
**
**  This file contains the main driver program for Snake.
    compile using g++ -Wall -g -o [customname] [filename]
**  Summary:
*************************************************/

#include "game.h"

int main() {
    Game game = Game(10, 20);
    game.render();
}
