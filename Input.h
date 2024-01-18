#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "Item.h"

typedef enum direction {
    STOPPED = 0,
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4,
} DIRECTION;

typedef struct Snake {
    size_t x;
    size_t y;
    int snakeNum;
    char head;
    char body;
    size_t length;
    DIRECTION direction;
    int lives;
    int score;
} SNAKE;


#define INITIAL_LENGTH      0
#define INITIAL_LIVES       3
#define INITIAL_SCORE       0
#define INITIAL_DIRECTION   0


#define UP_ARROW        72
#define DOWN_ARROW      80
#define RIGHT_ARROW     77
#define LEFT_ARROW      75
#define EXIT_BUTTON     27      // esc key
#define PAUSE_BUTTON    112     // P key 

// user control functions for snake game
SNAKE CreateSnake(size_t initX, size_t initY, char h, char b);
bool HandleInput(char ch, SNAKE s);
void MoveSnake(SNAKE* s);
void StartMenu();
void Redraw(size_t height, size_t width, SNAKE* s, ITEM* f); 
bool HitSomething(SNAKE* s, ITEM* t);
void PauseGame(void);
void ExitMenu();