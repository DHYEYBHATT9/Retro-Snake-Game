// CSCN71030-23W Project II: Group 3
// Alex Fridman, Dhyey Bhatt, Henil Patel, Jonathan Ward
// Snake Game

// border function declarations

#pragma once
#include "Snake.h"
#include <stdio.h>
#include "Item.h"

// default values for testing
#define HEIGHT 15
#define WIDTH  50
#define EMPTY  '.'
#define BORDER '#'

void ClearScreen(void);

void Redraw(size_t height, size_t width, SNAKE* s, ITEM* f);

void DrawBorder(size_t height, size_t width);

void DrawInterior(size_t height, size_t width);

void ExitMenu();
