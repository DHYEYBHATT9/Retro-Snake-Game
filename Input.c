#include"Input.h"
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

bool HandleInput(char ch, SNAKE s)
{
    bool validInput = true;
    if (s.snakeNum == 1)
    {
        switch (ch)
        {
        case '/':
            s.direction = STOPPED;
            break;

        case UP_ARROW:
            if (s.direction != SOUTH)
                s.direction = NORTH;
            break;

        case RIGHT_ARROW:
            if (s.direction != WEST)
                s.direction = EAST;
            break;

        case DOWN_ARROW:
            if (s.direction != NORTH)
                s.direction = SOUTH;
            break;

        case LEFT_ARROW:
            if (s.direction != EAST)
                s.direction = WEST;
            break;

        default:
            // return false for invalid input characters
            validInput = false;
            break;
        }
    }
    else
    {
        switch (ch)
        {
        case 'q':
            s.direction = STOPPED;
            break;

        case 'w':
            if (s.direction != SOUTH)
                s.direction = NORTH;
            break;

        case 'd':
            if (s.direction != WEST)
                s.direction = EAST;
            break;

        case 's':
            if (s.direction != NORTH)
                s.direction = SOUTH;
            break;

        case 'a':
            if (s.direction != EAST)
                s.direction = WEST;
            break;

        default:
            // return false for invalid input characters
            validInput = false;
            break;
        }
    }
    // check for pause and exit buttons
    if (ch == PAUSE_BUTTON) {
        return true;
    }
    else if (ch == EXIT_BUTTON)
        return false;

    return validInput;
}
////////////////////////////////////////////////////
void MoveSnake(SNAKE* s)
{
    switch (s->direction)
    {
    case NORTH:
        s->y--;
        break;

    case EAST:
        s->x++;
        break;

    case SOUTH:
        s->y++;
        break;

    case WEST:
        s->x--;
        break;
    }
}

void PauseGame(void)
{
    char input;
    do {
        input = getchar();
    } while (input != 'p' && input != 'P');
}

SNAKE CreateSnake(size_t initX, size_t initY, char h, char b)
{

    SNAKE s = { 0 };
    s.x = initX;
    s.y = initY;
    s.head = h;
    s.body = b;
    s.length = INITIAL_LENGTH;
    s.direction = INITIAL_DIRECTION;
    s.lives = INITIAL_LIVES;
    s.score = INITIAL_SCORE;
    return s;
}

bool HitSomething(SNAKE* s, ITEM* t)
{
    if (s->y == HEIGHT || s->y == 1 || s->x == WIDTH || s->x == 1) {
        s->x = WIDTH / 2;
        s->y = HEIGHT / 2;
        s->lives--;
        return true;
    }
    if (s->y == t->y && s->x == t->x) {
        s->score += 10;
        return true;
    }

    return false;
}