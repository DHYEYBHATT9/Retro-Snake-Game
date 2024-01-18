// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// declaration of Item object (food, powerups, etc)
#define RANGE_MIN     2
#define RANGE_MAX_Y   48
#define RANGE_MAX_X   15

#include "Item.h"
#include "Output.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void UpdateFoodPosition(ITEM* foodItem)
{
    // Seed the random number generator
    srand((unsigned)time(NULL));

    foodItem->symbol = FOOD_CHAR;
    // Generate random x and y positions within the limits
    foodItem->x = rand() % (RANGE_MAX_Y - RANGE_MIN) + RANGE_MIN;
    foodItem->y = rand() % (RANGE_MAX_X - RANGE_MIN) + RANGE_MIN;
}
//rand() % (max_number + 1 - minimum_number) + minimum_number


bool ItemTypeAppears(ITEM_TYPE type)
{
    if ((rand() % MAX_ODDS) < OddsOfItemType(type))
        return true;
    else
        return false;
}

int OddsOfItemType(ITEM_TYPE type)
{
    switch (type)
    {
    case FOOD:
        return FOOD_ODDS;

    case BIG_FOOD:
        return BIG_FOOD_ODDS;

    case LOSE_WEIGHT:
        return LOSE_WEIGHT_ODDS;

    case POISON:
        return POISON_ODDS;

    case WALL:
        return WALL_ODDS;

    case EXTRA_LIFE:
        return EXTRA_LIFE_ODDS;

    default:        // should never happen
        return false;
    }
}

char ItemCharFromType(ITEM_TYPE type)
{
    switch (type)
    {
    case FOOD:
        return FOOD_CHAR;

    case BIG_FOOD:
        return BIG_FOOD_CHAR;

    case LOSE_WEIGHT:
        return LOSE_WEIGHT_CHAR;

    case POISON:
        return POISON_CHAR;

    case WALL:
        return WALL_CHAR;

    case EXTRA_LIFE:
        return EXTRA_LIFE_CHAR;

    default:             // just in case
        return EMPTY;
    };
}

ITEM_TYPE ItemTypeFromChar(char ch)
{
    switch (ch)
    {
    case FOOD_CHAR:
        return FOOD;

    case BIG_FOOD_CHAR:
        return BIG_FOOD;

    case LOSE_WEIGHT_CHAR:
        return LOSE_WEIGHT;

    case POISON_CHAR:
        return POISON;

    case WALL_CHAR:
        return WALL;

    case EXTRA_LIFE_CHAR:
        return EXTRA_LIFE;

    default:            // just in case
        return FOOD;
    }
}

void EatItem(SNAKE* s, ITEM_TYPE type)
{
    switch (type)
    {
    case FOOD:
        GrowSnake(s);
        break;

    case BIG_FOOD:
        for (int i = 0; i < BIG_FOOD_VALUE; ++i)
            GrowSnake(s);
        break;

    case LOSE_WEIGHT:
        LoseWeight(s);

    case POISON:
        return POISON_CHAR;

    case WALL:
        KillSnake(s);

    case EXTRA_LIFE:
        s->lives++;
    }
}
