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
* <Function declaration>
*
*/

#pragma once

#include"Constants.h"

void InputValidation(int& boardSize, int& amountOfMines);

void CreateBoardBeforeStart(char myBoard[][MAX_SIZE], char playingBoard[][MAX_SIZE],
							const int boardSize);

void placeMines(int mines[][2], const int amountOfMines, char playingBoard[][MAX_SIZE],
				const int boardSize);

void printBoard(char myBoard[][MAX_SIZE], const int boardSize);

bool isValid(int row, int col, const int boardSize);

bool isMine(int row, int col, char board[][MAX_SIZE]);

int countAdjacentMines(int row, int col, int mines[][2],
	char playingBoard[][MAX_SIZE], const int boardSize);

char* makeMove(int& x, int& y);

bool playMinesweeperUtil(char myBoard[][MAX_SIZE], char playingBoard[][MAX_SIZE],
	int mines[][2], int amountOfMines,
	int boardSize, int row, int col, int* movesLeft, char* command);

void replaceMine(int row, int col, char board[][MAX_SIZE], int boardSize);

void playMinesweeper(int boardSize, int amountOfMines);
