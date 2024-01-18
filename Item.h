// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// declaration of item routines (food, powerups, etc)

#pragma once
#include "Snake.h"
#include <stdbool.h>

#define MAX_ITEMS   3    // maximum number of items on the board at once

// probability of different items appearing per cycle (out of 100)
#define FOOD_ODDS           50
#define BIG_FOOD_ODDS       15
#define LOSE_WEIGHT_ODDS    10
#define POISON_ODDS         10
#define WALL_ODDS           5
#define EXTRA_LIFE_ODDS     5
#define MAX_ODDS            100

// in-game symbols to represent different items
#define FOOD_CHAR           'F'
#define BIG_FOOD_CHAR       'B'
#define LOSE_WEIGHT_CHAR    'W'
#define POISON_CHAR         'P'
#define WALL_CHAR           '#'
#define EXTRA_LIFE_CHAR     'L'

// minimum safe distance for food to spawn from snake head (in orthogonal direction)
#define MIN_SAFE_DISTANCE   4

typedef enum ItemType {
    FOOD        = 0,
    BIG_FOOD    = 1,
    LOSE_WEIGHT = 2,
    POISON      = 3,
    WALL        = 4,

    // EXTRA_LIFE should always be the highest value - see SpawnItem() in Item.c
    EXTRA_LIFE   = 5,
} ITEM_TYPE;

typedef struct Item {
    ITEM_TYPE type;
    char symbol;
    size_t x;
    size_t y;
} ITEM;

void UpdateFoodPosition(ITEM* foodItem);
bool ItemTypeAppears(ITEM_TYPE type);
int OddsOfItemType(ITEM_TYPE type);
char ItemCharFromType(ITEM_TYPE type);
ITEM_TYPE ItemTypeFromChar(char ch);

void EatItem(SNAKE* s, ITEM_TYPE type);
bool HitSomething(SNAKE* s, ITEM* t);

