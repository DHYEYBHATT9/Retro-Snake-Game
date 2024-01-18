// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// menu implementation

#include "Menu.h"
#include "File_io.h"
#include "Item.h"
#include <stdio.h>
#include <stdlib.h>

void StartMenu()
{
    printf("*************************************************************************\n");
    printf("*\t  ____  ______   ___      _____       __  ___   ________\t*\n");
    printf("*\t / ___| |     \\  | |     /  _  \\     |  |/  /  | ______|\t*\n");
    printf("*\t| |___  |  |\\  \\ | |    /  /_\\  \\    |  /  /   | |_____\t\t*\n");
    printf("*\t|___  | |  | \\  \\| |   /  ___ \\  \\   |  \\  \\   | _____|\t\t*\n");
    printf("*\t___|  | |  |  \\    |  /  /     \\  \\  |  |\\  \\  | |_____\t\t*\n");
    printf("*\t|_____| |__|   \\___| /__/       \\__\\ |__| \\__\\ |_______|\t*\n");
    printf("*************************************************************************\n\n");
    puts("PRESS ENTER IF YOU WISH TO DARE OR Q TO QUIT THE GAME - CHOOSE WISELY!\n");
    puts("FOR CONTROLS AND GAMNE FUNCTIONALITY PRESS P!!!\n");

    //*****************************PLEASE DON'T FIDDLE AROUND MENU*************************
}

// print item types and game instructions
void PrintHelp()
{
    system("cls");

    printf("==================================================\n");
    printf("                     SNAKE HELP\n");
    printf("==================================================\n\n");

    printf("Welcome to the Snake game!\n\n");

    printf("GAMEPLAY:\n");
    printf("- Use the WASD keys to move the snake around the board.\n");
    printf("- Collect the food items to increase your score.\n");
    printf("- Don't run into the walls or the snake's body, or you'll lose a life.\n");
    printf("- The game ends when you run out of lives.\n\n");

    printf("CONTROLS:\n");
    printf("- W: Move up\n");
    printf("- A: Move left\n");
    printf("- S: Move down\n");
    printf("- D: Move right\n");
    printf("- P: Pause the game\n\n");

    printf("TIPS:\n");
    printf("- Try to collect as much food as possible to increase your score.\n");
    printf("- Use the walls to your advantage by trapping the food items against them.\n");
    printf("- Be careful not to run into the snake's body, especially as it gets longer.\n\n");

    printf("Good luck, and have fun playing the Snake game!\n\n");

    getchar();

}

bool RunOptionsMenu()
{
    // use menu to get user prefs and store them in file

    return true;
}
