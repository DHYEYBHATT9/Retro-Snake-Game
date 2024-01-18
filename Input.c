// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// input functions implementation

#define _CRT_SECURE_NO_WARNINGS
#include "Input.h"
#include "Snake.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAX_STRING_TO_DOUBLE		20
#define MAX_STRING_TO_INT		    12      // more than enough for unsigned long

#include"Input.h"
#include<stdbool.h>

void HandleInput(SNAKE* s)
{
    if (_kbhit()) // scans for input returns a non-zero if nothing
    {

        switch (_getch())
        {
        case 'w':
            if (s->direction != SOUTH)
                s->direction = NORTH;
            break;

        case 'd':
            if (s->direction != WEST)
                s->direction = EAST;
            break;

        case 's':
            if (s->direction != NORTH)
                s->direction = SOUTH;
            break;

        case 'a':
            if (s->direction != EAST)
                s->direction = WEST;
            break;

        case 'q':
            s->direction = STOPPED;
            break;

        default:
            break;
        }

    };
}


void PauseGame(void)
{
    while (_getch() != PAUSE_BUTTON)
        continue;
}

int checkKeysPressed(int direction)
{
    int pressed;

    {
        pressed = getchar();
        if (direction != pressed)
        {
            if (pressed == DOWN_ARROW && direction != UP_ARROW) // not letting user write the opposite 
                direction = pressed;
            else if (pressed == UP_ARROW && direction != DOWN_ARROW)
                direction = pressed;
            else if (pressed == LEFT_ARROW && direction != RIGHT_ARROW)
                direction = pressed;
            else if (pressed == RIGHT_ARROW && direction != LEFT_ARROW)
                direction = pressed;
            else if (pressed == EXIT_BUTTON || pressed == PAUSE_BUTTON);
            // function to pause or exit game;
        }
    }
    return(direction);
}

// this and  following functions are generic user input routines
void removeNewLineFromString(char* string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '\n')
            string[i] = '\0';
    }
}

int countOfCharInString(char* string, char c)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == c)
            count++;
    }
    return count;
}

bool stringIsNumeric(char* string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!(isdigit(string[i]) || string[i] == '.'
            || string[i] == '-' || string[i] == '+'))
            return false;
    }

    // should be at most 1 period, and 1 plus or minus sign at the beginning
    int countOfPlus = countOfCharInString(string, '+');
    int countOfMinus = countOfCharInString(string, '-');
    if (countOfCharInString(string, '.') <= 1
        && countOfPlus <= 1 && countOfMinus <= 1)
    {
        if (countOfPlus == 1 && countOfMinus == 0 && string[0] == '+')
            return true;
        else if (countOfMinus == 1 && countOfPlus == 0 && string[0] == '-')
            return true;
        else if (countOfMinus == 0 && countOfPlus == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool getStringInput(char* userInput, size_t maxLength)
{
    if (fgets(userInput, (int)maxLength, stdin) == NULL)
        return false;
    removeNewLineFromString(userInput);         // optional

    if (strlen(userInput) > 0)
        return true;
    else
        return false;
}

bool getIntegerInput(int* userInput)
{
    char input[MAX_STRING_TO_INT] = { 0 };
    if (fgets(input, (int)MAX_STRING_TO_INT, stdin) == NULL)
        return false;
    removeNewLineFromString(input);

    if (!stringIsNumeric(input))
        return false;
    else
    {
        *userInput = atoi(input);
        return true;
    }
}

// for collecting single char e.g. for menu inputs, and ignoring everything 
// that comes afterward (e.g. the dangling newline)
char returnSingleChar(void)
{
    char firstChar = getc(stdin);
    char garbage = ' ';
    while (garbage != '\n' && garbage != EOF)
        garbage = getc(stdin);
    return firstChar;
}

bool yes(void)
{
    char ch = returnSingleChar();
    if (ch == 'y' || ch == 'Y')
        return true;
    else
        return false;
}
