#pragma once

#include"Constants.h"

void InputValidation(int& boardSize, int& amountOfMines);

void CreateBoardBeforeStart(char myBoard[][MAX_SIZE], const int boardSize);

void printBoard(char myBoard[][MAX_SIZE], const int boardSize);

bool isValid(int row, int col, const int boardSize);

bool isMine(int row, int col, char board[][MAX_SIZE]);

void makeMove(int* x, int* y);
