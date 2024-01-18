//#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#define HEIGHT 25
//#define WIDTH  100
//#define UP 72
//#define DOWN 80
//#define LEFT 75
//#define RIGHT 77
//
//void StartMenu();
//void Border();
//void Snake();
//int play(int snakelen, int xsnake[snakelen], int ysnake[snakelen], int size, char grid[size][size]); 
//
//
//#define WIDTH 20
//#define HEIGHT 20
//
//int x, y, fruitX, fruitY, score, gameover;
//int tailX[100], tailY[100], ntail;
//
//enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
//enum eDirection dir;
//
//void Setup()
//{
//    gameover = 0;
//    dir = STOP;
//    x = WIDTH / 2;
//    y = HEIGHT / 2;
//    fruitX = rand() % WIDTH;
//    fruitY = rand() % HEIGHT;
//    score = 0;
//}
//
//void Draw()
//{
//    system("cls");
//    for (int i = 0; i < WIDTH + 2; i++)
//        printf("#");
//    printf("\n");
//
//    for (int i = 0; i < HEIGHT; i++)
//    {
//        for (int j = 0; j < WIDTH; j++)
//        {
//            if (j == 0)
//                printf("#");
//
//            if (i == y && j == x)
//                printf("O");
//            else if (i == fruitY && j == fruitX)
//                printf("F");
//            else
//            {
//                int print = 0;
//                for (int k = 0; k < ntail; k++)
//                {
//                    if (tailX[k] == j && tailY[k] == i)
//                    {
//                        printf("o");
//                        print = 1;
//                    }
//                }
//                if (!print)
//                    printf(" ");
//            }
//
//            if (j == WIDTH - 1)
//                printf("#");
//        }
//        printf("\n");
//    }
//
//    for (int i = 0; i < WIDTH + 2; i++)
//        printf("#");
//    printf("\n");
//
//    printf("Score: %d\n", score);
//}
//
//void Input()
//{
//    if (_kbhit())
//    {
//        switch (_getch())
//        {
//        case 'a':
//            dir = LEFT;
//            break;
//        case 'd':
//            dir = RIGHT;
//            break;
//        case 'w':
//            dir = UP;
//            break;
//        case 's':
//            dir = DOWN;
//            break;
//        case 'x':
//            gameover = 1;
//            break;
//        }
//    }
//}
//
//void Logic()
//{
//    int prevX = tailX[0];
//    int prevY = tailY[0];
//    int prev2X, prev2Y;
//    tailX[0] = x;
//    tailY[0] = y;
//    for (int i = 1; i < ntail; i++)
//    {
//        prev2X = tailX[i];
//        prev2Y = tailY[i];
//        tailX[i] = prevX;
//        tailY[i] = prevY;
//        prevX = prev2X;
//        prevY = prev2Y;
//    }
//
//    switch (dir)
//    {
//    case LEFT:
//        x--;
//        break;
//    case RIGHT:
//        x++;
//        break;
//    case UP:
//        y--;
//        break;
//    case DOWN:
//        y++;
//        break;
//    default:
//        break;
//    }
//
//    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
//    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;
//
//    for (int i = 0; i < ntail; i++)
//    {
//        if (tailX[i] == x && tailY[i] == y)
//            gameover = 1;
//    }
//
//    if (x == fruitX && y == fruitY)
//    {
//        score += 10;
//        fruitX = rand() % WIDTH;
//        fruitY = rand() % HEIGHT;
//        ntail++;
//    }
//}
//
//
//
//#include"MainHeader.h"
//
//int play(int snakelen, int xsnake[snakelen], int ysnake[snakelen], int size, char grid[size][size])
//{
//    int score = 0;
//
//    while (1)
//    {
//        char dir;
//        scanf("%c", &dir);
//
//        int proposed_xhead = xsnake[0];
//        int proposed_yhead = ysnake[0];
//
//        switch (dir)
//        {
//        case 'w': // up
//            proposed_yhead--;
//            break;
//
//        case 's': // down
//            proposed_yhead++;
//            break;
//
//        case 'a': // left
//            proposed_xhead--;
//            break;
//
//        case 'd': // right
//            proposed_xhead++;
//            break;
//
//        default: // ignore this invalid char
//            continue;
//        }
//
//        // first make sure we didn't go off the edge of the field
//        if (proposed_yhead <= 0 || proposed_yhead >= (size - 1)
//            || proposed_xhead <= 0 || proposed_xhead >= (size - 1))
//        {
//            // would head off the maze, LOSE
//            break;
//        }
//
//        const char char_at_proposed_head = grid[proposed_yhead][proposed_xhead];
//
//        // now make sure we're not bumping into ourself
//        if (char_at_proposed_head == '@'    // we shouldn't ever be able to bump into our head
//            || char_at_proposed_head == '*')   // we bumped into our tail
//        {
//            break; // would run into ourself: LOSE
//        }
//
//        // NOW we know it's a legal move. Did we find the food?
//
//        if (char_at_proposed_head == 'X')
//        {
//            // found the food!
//            // update score, set new food, etc.
//            score += 10;
//        }
//
//        // blank out the former tail; we're about to lose that position
//        grid[ysnake[snakelen - 1]]
//            [xsnake[snakelen - 1]] = ' ';
//
//        // shift all items down in the array, dropping the last one
//
//        for (int i = snakelen - 1; i > 0; i--)
//        {
//            xsnake[i] = xsnake[i - 1];
//            ysnake[i] = ysnake[i - 1];
//        }
//
//        xsnake[0] = proposed_xhead;
//        ysnake[0] = proposed_yhead;
//
//        drawsnake(snakelen, xsnake, ysnake, size, grid);
//
//        system("cls");
//        printGrid(size, grid);
//    }
//
//    return score;
//}
//
