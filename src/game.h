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

/*  The Snake class keeps tracks of the snak's position and direction of travel
    The positions of the snake will be stored in an array of arrays, each index consisting of an x,y component
    The direction of travel will be stored in arrays aswell, using the concept of vectors
*/
class Snake {
    vector<vector<int>> body_;
    vector<vector<int>> direction_;
public:
    // constructor, snakes need initial position and direction
    Snake(vector<vector<int>> init_body, vector<vector<int>> init_direction) {
        body_ = init_body;
        direction_ = init_direction;
    }

    /*  take_step takes input position and adds this position to the front of the snake's body
        the back position of the snake will be deleted
    */
    void take_step(vector<int> position) {
        
    }
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