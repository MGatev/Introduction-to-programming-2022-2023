/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Martin Gatev
* @idnumber 0MI0600143* @compiler Visual Studio
*
* <Function declarations for the helper functions>
*
*/

#pragma once

#include "Constants.h"

bool isValid(int row, int col, const int boardSize);

bool isMine(int row, int col, char board[][MAX_SIZE]);

int countAdjacentMines(int row, int col, int mines[][2],
	char playingBoard[][MAX_SIZE], const int boardSize);

char* makeMove(int& x, int& y);

void replaceMine(int row, int col, char board[][MAX_SIZE], int boardSize);