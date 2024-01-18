// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// file I/O function declarations

#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "Snake.h"

#define MAX_FILE_NAME    150
#define LONGEST_LINE     100
#define MAX_NAME         20
#define MAX_DATE_LEN     30

typedef struct Score {
    time_t date;
    int score;
    char username[MAX_NAME];
} SCORE;

SCORE createScore(time_t d, int s, char* u);
void deleteScore(SCORE* s);

bool appendScoreToFile(char* dataFileName, SCORE* s);
void printScoreToStream(FILE* stream, SCORE* s);

void displayScore(SCORE* s);
bool displayScoreFromStream(FILE* stream);
bool displayAllScoreData(char* DataFileName);

bool copyFile(char* originalFileName, char* newFileName);
bool backupDataFile(char* dataFileName);
void displayDate(time_t tim);
void displayTime(time_t tim);
void PrintSnakeFile(SNAKE* s);
