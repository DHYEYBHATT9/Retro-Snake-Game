#include "Item.h"
#include <time.h>
#include <stdlib.h>


void UpdateFoodPosition(ITEM* foodItem)
{
    // Seed the random number generator
    srand((unsigned)time(NULL));

    foodItem->symbol = FOOD_CHAR;
    // Generate random x and y positions within the limits
    foodItem->x = rand() % (WIDTH - 2) + 1;
    foodItem->y = rand() % (HEIGHT - 2) + 1;
}