// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// border function declarations

#include "Output.h"
#include "Item.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void ClearScreen(void)
{
#ifdef _WIN32           // for windows
    system("cls");
#else                   // for unix or macos
    system("clear");
#endif
}

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
            else {
                bool isBody = false;
                for (int k = 0; k < s->length; k++)
                {
                    if (i == s->tail_y[k] && j == s->tail_x[k])
                    {
                        printf("%c", s->body); // print the snake's body at its position
                        isBody = true;
                        break;
                    }
                }
                if (!isBody)
                {
                    printf(" "); // print a space for all other positions
                }
            }
        }
        printf("\n");
    }
    printf("SCORE = %d\t\t\t\tLIVES = %d", s->score, s->lives);
}

void DrawBorder(size_t height, size_t width)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if (i == 1 || i == height || j == 1 || j == width)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void DrawInterior(size_t height, size_t width)
{
    // move cursor so you don't clear entire screen (ie. border stays same)


}

void ExitMenu()
{
    system("cls");
    printf("\n\n");
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
    printf("\n\n");

    puts("Better luck next time, press ENTER to exit the game.\n");
    getchar();
}