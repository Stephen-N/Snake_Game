/*************************************************
**  Name: game.h
**  PreCondition: N/A
**  PostCondition: N/A
*************************************************/

#ifndef GAME_H 
#define GAME_H
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Snake {
    
};

class Apple {
    
};

class Game {
    int height_ = 0; // member variable denoted by trailing '_'
    int width_ = 0;  
public:
    // constructor, sets the height and width of the board
    Game(int height, int width) { 
        height_ = height;
        width_ = width;
    }

    // Creates board that snake will move in
    void render() {
        printf("Height: %i \n", height_);
        printf("Width: %i \n", width_);

        vector<vector<char>> board;
        for (int row_x = 0; row_x < height_; row_x++) {
            vector<char> row;
            for (int column_y = 0; column_y < width_; column_y++) {
                if ((row_x == 0 && column_y == 0) || (row_x == height_-1 && column_y == 0) || (row_x == 0 && column_y == width_-1) || (row_x == height_-1 && column_y == width_-1)) {
                    // adds '+' to corners of board, width and height is subtracted by 1 due to row_x and column_y starting at 0
                    row.push_back('+');
                }
                else if ((row_x > 0 && row_x < height_-1) && (column_y == 0 || column_y == width_-1)) {
                    // adds walls of board
                    row.push_back('|');
                }
                else if ((row_x > 0 && row_x < height_-1) && (column_y > 0 || column_y < width_-1)) {
                    // adds empty space inside board
                    row.push_back(' ');
                }
                else {
                    // adds upper and lower boundary of board
                    row.push_back('-');
                }
            }
            board.push_back(row);
        }

        // Prints the matrix
        for (long unsigned int row_x = 0; row_x < board.size(); row_x++) {
            for (long unsigned int column_y = 0; column_y < board[row_x].size(); column_y++) {
                cout << board[row_x][column_y];
            }
            cout << endl;
        }
    }
};

#endif