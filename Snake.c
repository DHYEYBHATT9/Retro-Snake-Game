// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// snake functions

#include <stdbool.h>
#include <stdlib.h>
#include "Snake.h"
#include "Item.h"
#include "Input.h"
#include "Output.h"
#include <windows.h>
;

SNAKE* CreateSnake(int initX, int initY, char h, char b)
{
    SNAKE* s = malloc(sizeof(SNAKE));
    s->x = initX;
    s->y = initY;
    s->head = h;
    s->body = b;
    s->length = 1;
    s->direction = INITIAL_DIRECTION;
    s->lives = INITIAL_LIVES;
    s->score = INITIAL_SCORE;
    return s;
}

bool HitSomething(SNAKE* s, ITEM* t)
{
    if (s->y == HEIGHT + 1 || s->y == 0 || s->x == WIDTH || s->x == 1) {
        s->x = WIDTH / 2;
        s->y = HEIGHT / 2;
        s->lives--;
        return true;
    }
    if (s->y == t->y && s->x == t->x) {
        s->score += 10;
        s->length++;
        UpdateFoodPosition(t);
        return true;
    }
    for (int i = 0; i < s->length - 1; i++) {
        if (s->y == s->tail_y[i] && s->x == s->tail_x[i]) {
            s->x = WIDTH / 2;
            s->y = HEIGHT / 2;
            s->lives--;
            return true;
        }
    }
    return false;
}


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

    case STOPPED:
        break;
    default:
        break;
    };
}

void SnakeBodyMovement(SNAKE* s)
{
    int i;
    int prevX = s->tail_x[0];
    int prevY = s->tail_y[0];
    int prev2X, prev2Y;
    s->tail_x[0] = s->x;
    s->tail_y[0] = s->y;

    for (i = 1; i < s->length; i++)
    {
        prev2X = s->tail_x[i];
        prev2Y = s->tail_y[i];
        s->tail_x[i] = prevX;
        s->tail_y[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}

void GrowSnake(SNAKE* s)
{
    if (s->head == FOOD_CHAR) { // head intersects with food item 
        s->length++;
        s->score += FOOD_VALUE;
    }
}

void KillSnake(SNAKE* s)
{
    s->length = 0;
    s->lives--;
    if (s->lives < 1)
    {
        exit(1);
        // GAME OVER
    }
    else
    {
        ;
        // RESPAWN
    }
}

void LoseWeight(SNAKE* s)
{
    s->length--;
    s->score += LOSE_WEIGHT_VALUE;
}

void PoisonSnake(SNAKE* s)
{
    s->score += POISON_VALUE;
}

void FreeSnake(SNAKE* s)
{
    free(s);
}
