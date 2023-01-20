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
* <Function definitions to play the game>
*
*/

#include<iostream>
#include "Initialise.h"
#include "GameHelp.h"

using namespace std;

// A Recursive Function to play the Minesweeper Game
bool playMinesweeperUtil(char myBoard[][MAX_SIZE], char playingBoard[][MAX_SIZE],
	int mines[][2], int amountOfMines,
	int boardSize, int row, int col, int* movesLeft, char* command)
{
	bool isMark{}, isUnmark{}, isOpen{};

	//'read' the user's command
	if (command[0] == 'm' && command[1] == 'a' &&
		command[2] == 'r' && command[3] == 'k')
	{
		isMark = true;
	}

	else if (command[0] == 'o' && command[1] == 'p' &&
		command[2] == 'e' && command[3] == 'n')
	{
		isOpen = true;
	}
	else
	{
		isUnmark = true;
	}

	//If the user wants to mark the cell
	if (isMark == true)
	{
		myBoard[row][col] = '?';
		return (false);
	}

	//If the user want to unmark the cell
	else if (isUnmark == true)
	{
		if (myBoard[row][col] == '?')
		{
			myBoard[row][col] = '-';
		}

		else
		{
			printf("\n\n\n                                           ");
			printf("This cell hasn't been marked!\n\n\n\n");
		}

		return (false);
	}

	//If the user wants to open a cell
	else if (isOpen == true)
	{
		// Base Case
		if ((myBoard[row][col] != '-') && (myBoard[row][col] != '?'))
			return (false);

		// You opened a mine
		// Game Over
		if (playingBoard[row][col] == '*')
		{
			myBoard[row][col] = '*';

			//Print where all the mines are
			for (int i = 0; i < amountOfMines; i++)
			{
				myBoard[mines[i][0]][mines[i][1]] = '*';
			}

			printBoard(myBoard, boardSize);

			printf("\nYou lost!\n");

			return (true);
		}

		else
		{
			// Calculate the number of adjacent mines and put it
			// on the board
			int amountOfAdjacentMines = countAdjacentMines(row, col, mines, playingBoard, boardSize);

			(*movesLeft)--;

			myBoard[row][col] = amountOfAdjacentMines + '0';

			if (!amountOfAdjacentMines)
			{
				//Checking if the 'neighbour' cell is valid
				//Checking if there is a mine there
				//Checking the cells around the current cells
				//clockwise starting from 12 o'clock 

				//up 'neighbour' - 12 o'clock
				if (isValid(row - 1, col, boardSize) == true)
				{
					if (isMine(row - 1, col, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row - 1, col, movesLeft, command);
				}

				//diagonal up-right 'neighbour' - 1:30 o'clock
				if (isValid(row - 1, col + 1, boardSize) == true)
				{
					if (isMine(row - 1, col + 1, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row - 1, col + 1, movesLeft, command);
				}

				//right 'neighbour' - 3 o'clock
				if (isValid(row, col + 1, boardSize) == true)
				{
					if (isMine(row, col + 1, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row, col + 1, movesLeft, command);
				}

				//diagonal down-right 'neighbour' - 4:30 o'clock
				if (isValid(row + 1, col + 1, boardSize) == true)
				{
					if (isMine(row + 1, col + 1, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row + 1, col + 1, movesLeft, command);
				}

				//down 'neighbour' - 6 o'clock
				if (isValid(row + 1, col, boardSize) == true)
				{
					if (isMine(row + 1, col, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row + 1, col, movesLeft, command);
				}

				//diagonal down-left 'neighbour' - 7:30 o'clock
				if (isValid(row + 1, col - 1, boardSize) == true)
				{
					if (isMine(row + 1, col - 1, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row + 1, col - 1, movesLeft, command);
				}

				//left 'neighbour' - 9 o'clock
				if (isValid(row, col - 1, boardSize) == true)
				{
					if (isMine(row, col - 1, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row, col - 1, movesLeft, command);
				}

				//diagonal up-left 'neighbour' - 7:30 o'clock
				if (isValid(row - 1, col - 1, boardSize) == true)
				{
					if (isMine(row - 1, col - 1, playingBoard) == false)
						playMinesweeperUtil(myBoard, playingBoard, mines, amountOfMines,
							boardSize, row - 1, col - 1, movesLeft, command);
				}
			}

			return (false);
		}
	}
}



// A Function to play Minesweeper game
void playMinesweeper(int boardSize, int amountOfMines)
{
	// Initially the game is not over
	bool gameOver = false;

	// Actual Board and My Board
	char realBoard[MAX_SIZE][MAX_SIZE], myBoard[MAX_SIZE][MAX_SIZE];

	int movesLeft = boardSize * boardSize - amountOfMines;
	int x{}, y{};
	int mines[MAX_MINES][2]; // stores (x,y) coordinates of all mines.

	CreateBoardBeforeStart(realBoard, myBoard, boardSize);

	// Place the Mines randomly
	placeMines(mines, amountOfMines, realBoard, boardSize);

	// You are in the game until you have not opened a mine

	int currentMoveIndex = 0;

	while (gameOver == false)
	{
		printf("\n");
		printf("Current Status of Board : \n");
		printf("\n");
		printBoard(myBoard, boardSize);

		char* command = makeMove(x, y);

		// This is to guarantee that the first move is
		// always safe
		if (currentMoveIndex == 0)
		{
			// If the first move is a mine
			// then we remove the mine from that location
			if (isMine(x, y, realBoard) == true)
				replaceMine(x, y, realBoard, boardSize);
		}

		currentMoveIndex++;

		gameOver = playMinesweeperUtil(myBoard, realBoard, mines, amountOfMines,
			boardSize, x, y, &movesLeft, command);

		if ((gameOver == false) && (movesLeft == 0))
		{
			printf("\nYou won !\n");
			gameOver = true;
		}
	}
	return;
}