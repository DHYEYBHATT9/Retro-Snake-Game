// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// snake struct and snake function declarations

#pragma once
#include <stdbool.h>
#include <stdio.h>


#define INITIAL_LENGTH      0
#define INITIAL_LIVES       3
#define INITIAL_SCORE       0
#define INITIAL_DIRECTION   0

// effects of different items on snake score
#define FOOD_VALUE          1
#define BIG_FOOD_VALUE      5
#define LOSE_WEIGHT_VALUE   3
#define POISON_VALUE        -5


typedef enum direction {
    STOPPED = 0,
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4,
} DIRECTION;

typedef struct Snake {
    int x;
    int y;
    char head;
    char body;
    int length;
    DIRECTION direction;
    int lives;
    int score;
    int tail_x[30];
    int tail_y[100];
} SNAKE;

SNAKE* CreateSnake(int initX, int initY, char h, char b);
void SnakeBodyMovement(SNAKE* s);
void MoveSnake(SNAKE* s);
void GrowSnake(SNAKE* s);
void KillSnake(SNAKE* s);
void LoseWeight(SNAKE* s);
void PoisonSnake(SNAKE* s);
void FreeSnake(SNAKE* s);
