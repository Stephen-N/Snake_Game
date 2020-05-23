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
#include <cmath>
using namespace std;

// Direction constants
vector<int> UP = {0, 1};
vector<int> DOWN = {0, -1};
vector<int> LEFT = {-1, 0};
vector<int> RIGHT = {1, 0};

/*  The Snake class keeps tracks of the snak's position and direction of travel
    The positions of the snake will be stored in an array of arrays, each index consisting of an x,y component
    The direction of travel will be stored in arrays aswell, using the concept of vectors
*/
class Snake {
    vector<vector<int>> body_;
    vector<int> direction_;
public:
    // default constructor
    Snake() = default;

    // constructor, snakes need initial position and direction
    Snake(vector<vector<int>> init_body, vector<int> init_direction) {
        body_ = init_body;
        direction_ = init_direction;
    }

    /*  take_step takes input position and adds this position to the front of the snake's body
        the back position of the snake will be deleted
    */
    void take_step(vector<int> position) {
        // adds input position to every part of the the body
        for (int i = 0; i < body_.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < body_[i].size(); j++) {
                body_[i][j] = body_[i][j] + position[j];      
            }
        }
    }

    // setter, sets direction of snake
    void set_direction(vector<int> direction) {
        direction_ = direction;
    }

    // getter, returns position of snake head
    vector<int> get_head() {
        return body_[0];
    }

    // getter, gets body coordinates of snake
    vector<vector<int>> get_body() {
        vector<vector<int>> body;
        for (int i = 0; i < this->body_.size(); i++) {
            body.push_back(this->body_[i]);
        }
        return body;
    }
};

class Apple {
    
};

/*
    The Game class executes the game
*/
class Game {
    int height_ = 0; // member variable denoted by trailing '_'
    int width_ = 0;
    Snake snake_;  
public:
    // constructor, sets the height and width of the board and creates Snake
    Game(int height, int width) { 
        height_ = height;
        width_ = width;
        snake_ = Snake({{2, -1}, {2, -2}, {2, -3}, {3, -3}}, UP);
    }

    // Creates board that snake will move in, displays snake on board
    void render() {
        printf("Height: %i \n", height_);
        printf("Width: %i \n", width_);

        vector<vector<char>> board;
        for (int row_y = 0; row_y < height_; row_y++) {
            vector<char> row;
            for (int column_x = 0; column_x < width_; column_x++) {
                if ((row_y == 0 && column_x == 0) || (row_y == height_-1 && column_x == 0) || (row_y == 0 && column_x == width_-1) || (row_y == height_-1 && column_x == width_-1)) {
                    // adds '+' to corners of board, width and height is subtracted by 1 due to row_y and column_x starting at 0
                    row.push_back('+');
                }
                else if ((row_y > 0 && row_y < height_-1) && (column_x == 0 || column_x == width_-1)) {
                    // adds walls of board
                    row.push_back('|');
                }
                else if ((row_y > 0 && row_y < height_-1) && (column_x > 0 || column_x < width_-1)) {
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
        
        // Prints the matrix and snake
        vector<vector<int>> body = snake_.get_body();
        for (int row_y = 0; row_y < board.size(); row_y++) {
            for (int column_x = 0; column_x < board[row_y].size(); column_x++) {
                vector<int> coordinate = {column_x, row_y};
                // check if snake or board should be printed in current position
                for (int i = 0; i < body.size(); i++) {
                    // if the current coordinate is the position where a part of the snake should be
                    if (coordinate[0] == body[i][0] && coordinate[1] == body[i][1]) { 
                        if (i == 0) {
                            board[row_y][column_x] = 'X';
                        }
                        else {
                            board[row_y][column_x] = 'O';
                        }
                    }
                }
                cout << board[row_y][column_x];
            }
            cout << endl;
        }

        
    }
};

#endif