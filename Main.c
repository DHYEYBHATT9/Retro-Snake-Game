// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

#include "Menu.h"
#include "Output.h"
#include "Item.h"
#include <stdlib.h>     // for exit() and srand()
#include <time.h>       // for use by srand()
#include <conio.h>


#ifdef _WIN32           // for windows
#include <windows.h>    // contains Sleep() on windows
#else                   // for unix or macos
#include <unistd.h>     // contains Sleep() on POSIX-compliant systems
#endif


int main(int argv, char* argc[])
{
    StartMenu();
    // if you want to play a song, in the quotation copy the pathway of the song you want to play
    // it will play in the background
    //PlaySound(TEXT("??????????????.wav"), NULL, SND_ASYNC);
    char CharStart = getchar();
    if (CharStart == 'q' || CharStart == 'Q') {
        ExitMenu();
        system("pause");
        exit(1);
    }

    if (CharStart == 'p' || CharStart == 'P') {
        PrintHelp();
        system("pause");
    }

    srand((unsigned)time(NULL));

    int height = atoi(argc[1]);
    int width = atoi(argc[2]);
    int initX = width / 2;
    int initY = height / 2;

    SNAKE* s1 = CreateSnake(initX + 3, initY + 3, '@', 'o');
    ITEM food;
    UpdateFoodPosition(&food);

    int numItems = 0;
    DIRECTION currentDirection = s1->direction;

    while (s1->lives > 0) {
        system("cls");
        Redraw(height, width, s1, &food);
        Sleep(100); // 50ms

        HandleInput(s1);
        MoveSnake(s1);
        HitSomething(s1, &food);
        SnakeBodyMovement(s1);
    }

    PrintSnakeFile(s1);
    FreeSnake(s1);

    ExitMenu();

    return 0;
}