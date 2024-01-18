#include "Item.h"
#include "Input.h"

void Redraw(size_t height, size_t width, SNAKE* s, ITEM* f)
{
    for (int i = 0; i <= height + 1; i++)
    {
        for (int j = 0; j <= width + 1; j++)
        {
            if (i == 0 || i == height + 1 || j == 0 || j == width + 1)
            {
                printf("#");    // border
            }
            else if (i == s->y && j == s->x)
            {
                printf("%c", s->head);    // print the snake head at its position
            }
            else if (i == f->y && j == f->x)
            {
                printf("%c", f->symbol);  // print the food symbol at its position
            }
            else
            {
                printf(" ");    // print a space for all other positions
            }
        }
        printf("\n");
    }
}

void ExitMenu()
{
    printf("    Y\n");
    printf("  .-^-.\n");
    printf(" /     \\      .- ~ ~ -.\n");
    printf("()     ()    /   _ _   `.\n");
    printf(" \\_   _/    /  /     \\   \\\n");
    printf("   | |     /  /       \\   \\\n");
    printf("   | |    /  /         )   )\n");
    printf("   \\ \\_ _/  /         /   /\n");
    printf("    \\_ _ _.'         /   /\n");
    printf("                    /   /\n");
    printf("                   /   /\n");
    printf("                  /   /\n");
    printf("                 (   (\n");
    printf("                  \\  \\\n");
    printf("                    \\   \\ - - - - \\   .'\n");
    printf("                      \\ _ _ _ _ _ . ~~~~~\n");

    puts("Better luck next time :)\n");
}