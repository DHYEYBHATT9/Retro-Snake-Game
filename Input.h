// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// input function declarations

#pragma once
#include "Snake.h"
#include <stdio.h>
#include <stdbool.h>

#define UP_ARROW        72
#define DOWN_ARROW      80
#define RIGHT_ARROW     77
#define LEFT_ARROW      75
#define EXIT_BUTTON     27      // esc key
#define PAUSE_BUTTON    112     // P key 

// user control functions for snake game
void HandleInput(SNAKE* s);
void PauseGame(void);
int checkKeysPressed(int direction);

// generic user input routines
void removeNewLineFromString(char* string);
int countOfCharInString(char* string, char c);
bool stringIsNumeric(char* string);

bool getStringInput(char* response, size_t max);
bool getIntegerInput(int* userInput);
char returnSingleChar(void);
bool yes(void);
