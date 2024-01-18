// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// file I/O functions implementation

#define _CRT_SECURE_NO_WARNINGS

#include "File_io.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

SCORE createScore(time_t d, int s, char* u)
{
    SCORE* newScore = (SCORE*)malloc(sizeof(SCORE));
    if (!newScore)
    {
        fputs("FATAL ERROR: unable to allocate memory\n\n", stderr);
        exit(EXIT_FAILURE);
    }
    newScore->date = d;
    newScore->score = s;

    memcpy(newScore->username, u, MAX_NAME);
    newScore->username[MAX_NAME - 1] = '\0';        // ensure null-terminated
    return *newScore;
}

void deleteScore(SCORE* s)
{
    free(s);
}

bool appendScoreToFile(char* dataFileName, SCORE* s)
{
    FILE* pDataFile;
    if ((pDataFile = fopen(dataFileName, "a")) == NULL)
        return false;

    printScoreToStream(s, pDataFile);
    fclose(pDataFile);
    return true;
}

void printScoreToStream(FILE* stream, SCORE* s)
{
    fprintf(stream, "%lld,%d,", s->date, s->score);
    fputs(s->username, stream);
    fputs("\n", stream);
}

void displayScore(SCORE* s)
{
    displayDate(s->date);
    printf(" - ");
    displayTime(s->date);
    printf("     |     ");
    fputs(s->username, stdout);
    printf("     |     ");
    printf("%d", s->score);
}

bool displayScoreFromStream(FILE* stream)
{
    if (feof(stream))
        return false;

    SCORE s = { 0, 0, "" };
    if ((fscanf(stream, "%lld,%d,", &s.date, &s.score)) != 2)
    {
        fprintf(stderr, "\nProblem reading score data from file.\n");
        s.date = 0;
        s.score = 0;
        return false;
    }
    char name[MAX_NAME] = { 0 };
    fgets(name, MAX_NAME, stream);
    removeNewLineFromString(name);
    memcpy(s.username, name, MAX_NAME);
    s.username[MAX_NAME - 1] = '\0';        // ensure null-terminated
    fputs(&s.username, stdout);
    fputs("\n", stdout);

    return true;
}

bool displayAllScoreData(char* dataFileName)
{
    FILE* pDataFile;
    if ((pDataFile = fopen(dataFileName, "r")) == NULL)
        return false;
    
    printf("****************************** HIGH SCORES ******************************\n");
    printf("*** DATE - TIME ************ USERNAME ************ SCORE ***\n");

    while (displayScoreFromStream(pDataFile))
        continue;

    fputs('\n', stdout);

    if (feof(pDataFile))    // successfully reached end of file
    {
        fclose(pDataFile);
        return true;
    }
    else
    {
        fprintf(stderr, "Error reading score data from file.");
        fclose(pDataFile);
        return false;
    }
}

bool copyFile(char* originalFileName, char* newFileName)
{
    FILE* pFileOrig;
    FILE* pFileCopy;

    if ((pFileOrig = fopen(originalFileName, "r")) == NULL)
        return false;

    if ((pFileCopy = fopen(newFileName, "w")) == NULL)
        return false;

    char ch;
    while ((ch = fgetc(pFileOrig)) != EOF);
    {
        fputc(ch, pFileCopy);
    }

    fclose(pFileOrig);
    fclose(pFileCopy);

    return true;
}

// backup pre-existing data in event of a sudden crash, or for archiving
bool backupDataFile(char* dataFileName)
{
    // timestamp file name
    char backupFileName[MAX_FILE_NAME];
    time_t now = time(NULL);
    const struct tm* pTimeNow = localtime(&now);

    if (strftime(backupFileName, sizeof(backupFileName),
        "score_data_%F_T%H%M%S%z.txt", pTimeNow) == 0)
    {
        fprintf(stderr, "unable to name backup data file");
        return false;
    }
    else if (!copyFile(dataFileName, backupFileName))
    {
        // usually this just means there's no previously existing data file
        // so we'll leave out the error message for now
        // printError("unable to create backup data file");
        return false;
    }
    return true;
}

void displayDate(time_t tim)
{
    char date[MAX_DATE_LEN] = { 0 };
    struct tm* t = localtime(tim);
    if (strftime(date, sizeof(date), "%Y %b %d", t) == 0)
        fprintf(stderr, "error generating date");
    else
        fputs(date, stdout);
}

void displayTime(time_t tim)
{
    char time[MAX_DATE_LEN] = { 0 };
    struct tm* t = localtime(tim);
    if (strftime(time, sizeof(time), "%H:%M", t) == 0)
        fprintf(stderr, "error generating date");
    else
        fputs(time, stdout);
}

//// not needed for now
//void printSnakeToStream(SNAKE* s, FILE* stream)
//{
//    fprintf(stream, "%d,%d,%d,%d,%d,%d,%c,%c\n", s->x, s->y, s->length, 
//        s->snakeNum, s->lives, s->score, s->direction, s->head, s->body);
//}

void PrintSnakeFile(SNAKE* s)
{
    // File Pointer declared
    FILE* ptr;

    // File opened
    ptr = fopen("HighScore.txt", "w+");

    // Failed Condition
    if (ptr == NULL) {
        printf("Error Occurred While writing to a text "
            "file !");
        exit(1);
    }

    // Data to be inserted
    fprintf(ptr, "Score: %d\n", s->score);
    fclose(ptr);

    printf("Your score has been written on file\n\n");

    return 0;
}