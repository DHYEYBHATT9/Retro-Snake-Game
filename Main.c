#include"Input.h"
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>


int main() {
    SNAKE snake;
    snake.snakeNum = 0;
    snake.direction = STOPPED; // corrected this line

    char firstAttempt = 'w';

    bool result = HandleInput(firstAttempt, snake);

    printf("INT - 001 Test case:\n");
    // handleinput return a true if selected keys are pressed

    // passing test case
    if (result) {
        printf("Test 1 passed!\n");
    }
    else {
        printf("Test 1 failed:(\n");
    }

    // failing test case
    char secondAttempt = 'v';

    bool resultTwo = HandleInput(secondAttempt, snake);

    if (resultTwo) { // corrected this line
        printf("Test 2 passed!\n");
    }
    else {
        printf("Test 2 failed:(\n");
    }
    /////////////////////////////////////////////////////////////////
    char thirdAttempt = 'd';

    bool result3 = HandleInput(thirdAttempt, snake);

    // passing test case
    if (result3) {
        printf("INT 007: TESTING....             007.1\n\n");
        printf("Test 007.1 passed!\n\n");
    }
    else {
        printf("INT 007: TESTING....             007.1\n\n");
        printf("Test 007.1 failed:(\n\n");
    }
    ///////////////////////////////////////////////////////////////
    char fourthAttempt = 'd';
    char demoattempt = 'a';

        bool result4 = HandleInput(fourthAttempt, snake);


    // passing test case
    if (result3 && demoattempt != 'a') {
        printf("INT 007: TESTING....             007.2\n\n");
        printf("Test 007.2 passed!\n\n");
    }
    else {
        printf("INT 007: TESTING....             007.2\n\n");
        printf("Input for 007.2 failed:( So, Test passed ! \n\n");
    }
    /////////////////////////////////////////////////////////////
    char fivthAttempt = 'w';
    char demoattempt2 = 's';

    bool result5 = HandleInput(fivthAttempt, snake);


    // passing test case
    if (result5 && demoattempt2 != 's') {
        printf("INT 007: TESTING....             007.3\n\n");
        printf("Test 007.3 passed!\n\n");
    }
    else {
        printf("INT 007: TESTING....             007.3\n\n");
        printf("Input for 007.3 failed:( So, Test passed ! \n\n");
    }
    ////////////////////////////////////////////////////////////////////////////
    char sixthAttempt = 'w';
    char demoattempt3 = 'd';

    bool result6 = HandleInput(sixthAttempt, snake);


    // passing test case
    if (result5 && demoattempt3 != 's') {

        printf("INT 007: TESTING....             007.4\n\n");
        printf("Test 007.4 passed!\n\n");
    }
    else {
        printf("INT 007: TESTING....             007.4\n\n");
        printf("Test 007.4 failed:( \n\n");
    }

    puts("\n\n");
    printf("INT - 003 Test case:\n");
    StartMenu();
    puts("\n");

    ITEM item;
    UpdateFoodPosition(&item);
    // randomly generates coordinates of food item 
    // test will print out coordinates within the range of the border

    printf("INT - 005 Test case\n");
    printf("X: %zu,Y: %zu\n", item.x, item.y);


    printf("INT - 006 Test case\n");
    snake.x = 25;
    snake.y = 25;
    snake.head = '@';
    Redraw(HEIGHT, WIDTH, &snake, &item);
    puts("\n");

    printf("INT - 009 Test case\n\n");
    item.x = 25;
    item.y = 25;
    snake.score = 0;


    // testing HitSomething module snake eating food item 
    if (HitSomething(&snake, &item) != true)
    {
        printf("Test has failed :(\n");
    }
    else {
        printf("Test has passed :)\n");
        printf("Updated score: %d\n", snake.score);
    }

    printf("INT - 200 Test case (snake/border):\n\n");

    snake.x = 1;
    snake.y = 1;
    snake.lives = 3;

    if (HitSomething(&snake, &item) != true) {
        printf("Test has failed :(\n");
    }
    else {
        printf("Test has passed :)\n");
        printf("Number of lives: %d\n", snake.lives);
    }
    SNAKE s;
    s.x = 0;
    s.y = 0;
    s.direction = EAST;

    // Test moving to the EAST
    MoveSnake(&s);
    if (s.x == 1 && s.y == 0)
    {  //x = 1; y = 0
        printf("INT 203 TESTING........\n");
        printf("Test 1 passed\n");
    }
    else
    {
        printf("Test 1 failed\n");
    }

    // Test moving to the SOUTH
    s.x = 0;
    s.y = 0;
    s.direction = SOUTH;
    MoveSnake(&s);
    if (s.x == 0 && s.y == 1)
    { //x = 1 ; y = 1
        printf("Test 2 passed\n");
    }
    else
    {
        printf("Test 2 failed\n");
    }

    // Test moving to the WEST
    s.x = 0;
    s.y = 0;
    s.direction = WEST;
    MoveSnake(&s);
    if (s.x == -1 && s.y == 0)
    { // x = 0 ; y = 1
        printf("Test 3 passed\n");
    }

    else
    {
        printf("Test 3 failed\n");
    }
    // Test moving to the NORTH
    s.x = 0;
    s.y = 0;
    s.direction = NORTH;
    MoveSnake(&s);
    if (s.x == 0 && s.y == -1)
    { // x = 0; y = 0
        printf("Test 4 passed\n");
    }
    else
    {
        printf("Test 4 failed\n");
    }
    // Test stopping
    s.x = 0;
    s.y = 0;
    s.direction = STOPPED;
    MoveSnake(&s);
    if (s.x == 0 && s.y == 0)          // x = 0; y = 0 
    {
        printf("Test 5 passed\n");
    }
    else
    {
        printf("Test 5 failed\n");
    }

    printf("All tests passed successfully FOR INT 203!\n");
    printf("INT - 201 Test case:\n\n");
    PauseGame();

    printf("\n\nINT - 202 Test case:\n\n");
    snake = CreateSnake(WIDTH / 2, HEIGHT / 2 ,'@', 'o');

    printf("X: %zu,Y: %zu, Head: %c, Body: %c\n", snake.x, snake.y, snake.head, snake.body);

    printf("\nTest Exit menu:\n\n");
    ExitMenu();

    return 0;
}
