#pragma once

#include"Constants.h"

void InputValidation(int& boardSize, int& amountOfMines);

void FillBoardBeforeStart(char myBoard[][MAX_SIZE], const int boardSize);

void printBoard(char myBoard[][MAX_SIZE], const int boardSize);


