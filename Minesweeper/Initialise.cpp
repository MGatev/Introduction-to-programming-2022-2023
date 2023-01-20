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
* <Function definitons to initialise the board and print the welcome message>
*
*/

#include<iostream>
#include "Initialise.h"

using namespace std;

//Function to print a message before the game starts
void PrintWelcomeMessage()
{
	printf("Welcome to the Minesweeper game!\n\n");
	printf("You win if you are able to reveal all non - mine cells and you lose if you open a mine.\n\n");
	printf("Here is how to play: \n\n");
	printf("You enter a command, row and a column where you want to do it.\n");
	printf("The commands can be:\n\n");
	printf("open --> to reveal a mine\n");
	printf("mark --> to mark a cell in which you think there is a mine\n");
	printf("unmark --> to unmark a marked cell\n\n");
	printf("The symbols used are:\n");
	printf("DASH(-) --> if the cell is unrevealed\n");
	printf("QUESTION MARK(?) --> if you 'mark' the cell\n");
	printf("ASTERIX(*) --> if you hit a mine this symbol appears\n\n");
	printf("Good luck and have fun!\n\n");
}

//Function to read the user's input at the start of the game
void InputValidation(int& boardSize, int& amountOfMines)
{
	PrintWelcomeMessage();

	printf("Please insert the dimensions (N) of the playing board (number between 3 and 10): ");

	cin >> boardSize;

	//board size validation
	for (int i = 0; boardSize < 3 || boardSize > 10; i++)
	{
		if (boardSize < 3 || boardSize > 10)
		{
			printf("\n");
			printf("You have entered incorrect size. Please insert a number between 3 and 10: ");

			cin >> boardSize;
		}
	}

	printf("\n");
	printf("Please choose how many mines do you want to play with (number between 1 and 3*N): ");

	cin >> amountOfMines;

	//amount of mines validation
	for (int i = 0; amountOfMines < 1 || amountOfMines >(3 * boardSize); i++)
	{
		if (amountOfMines < 3 || amountOfMines >(3 * boardSize))
		{
			printf("\n");
			printf("You have entered incorrect number.\nPlease insert a number between 1 and 3 * N,"
				"where N is the dimensions of the playing board : ");

			cin >> amountOfMines;
		}
	}

	printf("\n");
}

//Initialise the two boards
void CreateBoardBeforeStart(char myBoard[][MAX_SIZE], char playingBoard[][MAX_SIZE],
	const int boardSize)
{
	// Assign all the cells as mine-free
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			myBoard[i][j] = playingBoard[i][j] = '-';
		}
	}

	return;
}

//Place mines in the board which is not modified throughout the game
void placeMines(int mines[][2], const int amountOfMines, char playingBoard[][MAX_SIZE],
	const int boardSize)
{
	srand((unsigned int)time(NULL));

	//mines store the coordinates of where a mine is placed

	bool mark[MAX_SIZE * MAX_SIZE]{};

	for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++)
	{
		mark[i] = false;
	}

	// Continue until all random mines have been created.
	for (int i = 0; i < amountOfMines; )
	{
		int random = rand() % (boardSize * boardSize);
		int x = random / boardSize;
		int y = random % boardSize;

		// Add the mine if there isnt a mine there
		if (mark[random] == false)
		{
			//row and column index of the mine
			mines[i][0] = x;
			mines[i][1] = y;

			// Place the mine
			playingBoard[mines[i][0]][mines[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}

	return;
}

//Function to print the board
void printBoard(char myBoard[][MAX_SIZE], const int boardSize)
{
	printf("      ");

	for (int i = 0; i < boardSize; i++)
	{
		printf("%d      ", i);
	}

	printf("\n\n");

	for (int i = 0; i < boardSize; i++)
	{
		printf(" %d   ", i);

		for (int j = 0; j < boardSize; j++)
		{
			printf("|%c|    ", myBoard[i][j]);
		}

		printf("\n\n\n");
	}
}