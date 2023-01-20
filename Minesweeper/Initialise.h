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
* <Function declarations for initialising the game>
*
*/

#pragma once

#include "Constants.h"

void PrintWelcomeMessage();

void InputValidation(int& boardSize, int& amountOfMines);

void CreateBoardBeforeStart(char myBoard[][MAX_SIZE], char playingBoard[][MAX_SIZE],
	const int boardSize);

void placeMines(int mines[][2], const int amountOfMines, char playingBoard[][MAX_SIZE],
	const int boardSize);

void printBoard(char myBoard[][MAX_SIZE], const int boardSize);