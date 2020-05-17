/*************************************************
**  Name: game.h
**  PreCondition: N/A
**  PostCondition: N/A
*************************************************/

#ifndef GAME_H 
#define GAME_H
#include <stdio.h>

class Snake {
    
};

class Apple {
    
};

class Game {
    int height_ = 0; // member variable denoted by trailing '_'
    int width_ = 0; 
public:
    Game(int height, int width) { // constructor, sets the height and width of the board
        height_ = height;
        width_ = width;
    }

    void render() {
        printf("Height: %i \n", height_);
        printf("Width: %i \n", width_);
    }
};

#endif