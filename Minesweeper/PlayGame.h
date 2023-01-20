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
* <Function declarations to play the game>
*
*/

#pragma once

#include"Constants.h"

bool playMinesweeperUtil(char myBoard[][MAX_SIZE], char playingBoard[][MAX_SIZE],
	int mines[][2], int amountOfMines,
	int boardSize, int row, int col, int* movesLeft, char* command);

void playMinesweeper(int boardSize, int amountOfMines);
