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
* <Helper functions to do the logic behind the game>
*
*/

#include<iostream>
#include "GameHelp.h"

using namespace std;

//Checks if the given coordinates are valid
bool isValid(int row, int col, const int boardSize)
{
	if ((row >= 0 && row < boardSize) && (col >= 0 && col < boardSize))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Checks if on the given coordinates have a mine
bool isMine(int row, int col, char board[][MAX_SIZE])
{
	if (board[row][col] == '*')
		return (true);
	else
		return (false);
}

int countAdjacentMines(int row, int col, int mines[][2],
	char playingBoard[][MAX_SIZE], const int boardSize)
{
	//Checking if the 'neighbour' cell is valid
	//Checking if there is a mine there
	//and adding it to the counter
	//Checking the cells around the current cells
	//clockwise starting from 12 o'clock 

	int counter{};

	//up 'neighbour' - 12 o'clock
	if (isValid(row - 1, col, boardSize) == true)
	{
		if (isMine(row - 1, col, playingBoard) == true)
		{
			counter++;
		}
	}

	//diagonal up-right 'neighbour' - 1:30 o'clock
	if (isValid(row - 1, col + 1, boardSize) == true)
	{
		if (isMine(row - 1, col + 1, playingBoard) == true)
		{
			counter++;
		}
	}

	//right 'neighbour' - 3 o'clock
	if (isValid(row, col + 1, boardSize) == true)
	{
		if (isMine(row, col + 1, playingBoard) == true)
		{
			counter++;
		}
	}

	//diagonal down-right 'neighbour' - 4:30 o'clock
	if (isValid(row + 1, col + 1, boardSize) == true)
	{
		if (isMine(row + 1, col + 1, playingBoard) == true)
		{
			counter++;
		}
	}

	//down 'neighbour' - 6 o'clock
	if (isValid(row + 1, col, boardSize) == true)
	{
		if (isMine(row + 1, col, playingBoard) == true)
		{
			counter++;
		}
	}

	//diagonal down-left 'neighbour' - 7:30 o'clock
	if (isValid(row + 1, col - 1, boardSize) == true)
	{
		if (isMine(row + 1, col - 1, playingBoard) == true)
		{
			counter++;
		}
	}

	//left 'neighbour' - 9 o'clock
	if (isValid(row, col - 1, boardSize) == true)
	{
		if (isMine(row, col - 1, playingBoard) == true)
		{
			counter++;
		}
	}

	//diagonal up-left 'neighbour' - 10:30 o'clock
	if (isValid(row - 1, col - 1, boardSize) == true)
	{
		if (isMine(row - 1, col - 1, playingBoard) == true)
		{
			counter++;
		}
	}

	return counter;
}

//Get the user's move
char* makeMove(int& x, int& y)//, char* &command)
{
	// Take the input move
	printf("Enter your move, (command row column): ");

	char* command = new char[MAX_LENGTH_COMMAND];

	cin >> command >> x >> y;

	return command;
}

// A function to replace the mine from (row, col) and put an empty cell
// It is in order to make the first move safe
void replaceMine(int row, int col, char board[][MAX_SIZE], int boardSize)
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			// Find the first location in the board
			// which is not having a mine and put a mine
			// there.
			if (board[i][j] != '*')
			{
				board[i][j] = '*';
				board[row][col] = '-';
				return;
			}
		}
	}
	return;
}