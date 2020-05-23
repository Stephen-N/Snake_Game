# Snake Game
Play as a snake, eat apples and not yourself!

## Table of Contents
- [Snake Game](#snake-game)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Concepts to review](#concepts-to-review)
  - [What the Classes Do](#what-the-classes-do)
  - [Project Roadmap](#project-roadmap)

---

## Overview

- The game will play like the classic snake game with a few key things to keep in mind
  - Game will run in terminal (later browser and on Android)
  - Will be two player
  - Will be hosted online

---

## Concepts to review 

To be updated
- Classes, Header Files, Makefile, 2D Arrays,

---

## What the Classes Do
- **Snake**
  - Will store data about where the snake is and the direction it's heading.
  - Assuming the board exists where the bottom-left corner is (0,0), if the snake takes a step up, then the array value for the snake's direction will be UP (UP = {0,1}). 
      
    Similarly: Down = {0,-1}; LEFT = {-1, 0}; RIGHT = {1,0}
- **Apple**
  - Stores apple's location on the board
- **Game**
  - Executes the game. Receives input from the player, displays the board, tracks points, etc...

---

## Project Roadmap
1. Set up classes [Done]
2. Render empty board [Done]
3. Render snake [Currently In progress]
    - Let player move snake
4. Determine has player dies
5. Implement apple point system
    - Add multiple apples
6. Make game two player
7. Improve game UI
8. Make game run in browser
9. Host game online
10. Turn game into Android App
