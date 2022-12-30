#include<iostream>
#include"Functions.h"

using namespace std;

void InputValidation(int& boardSize, int& amountOfMines)
{
	cout << "Please insert the dimensions (N) of the playing board (number between 3 and 10):" << endl;

	cin >> boardSize;

	//board size validation
	for (int i = 0; boardSize < 3 || boardSize > 10; i++)
	{
		if (boardSize < 3 || boardSize > 10)
		{
			cout << "You have entered incorrect size. Please insert a number between 3 and 10." << endl;
			cin >> boardSize;
		}
	}

	cout << "Please choose how many mines do you want to play with (number between 1 and 3*N):" << endl;

	//int amountOfMines{};

	cin >> amountOfMines;

	//amount of mines validation
	for (int i = 0; amountOfMines < 1 || amountOfMines >(3 * boardSize); i++)
	{
		if (amountOfMines < 3 || amountOfMines >(3 * boardSize))
		{
			cout << "You have entered incorrect number. Please insert a number between 1 and 3 * N, where N is the dimensions of the playing board." << endl;
			cin >> amountOfMines;
		}
	}
}

void FillBoardBeforeStart(char myBoard[][MAX_SIZE], const int boardSize)
{
	// Assign all the cells as mine-free
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			myBoard[i][j] = '-';
		}
	}
}

void printBoard(char myBoard[][MAX_SIZE], const int boardSize)
{
	printf("    ");

	for (int i = 0; i < boardSize; i++)
	{
		printf("%d ", i);
	}

	printf("\n\n");

	for (int i = 0; i < boardSize; i++)
	{
		printf("%d   ", i);

		for (int j = 0; j < boardSize; j++)
		{
			printf("%c ", myBoard[i][j]);
		}

		printf("\n");
	}
}

int main()
{
	int boardSize{}, amountOfMines{};

	InputValidation(boardSize, amountOfMines);

	char board[MAX_SIZE][MAX_SIZE]{};

	FillBoardBeforeStart(board, boardSize);

	printBoard(board, boardSize);

	return 0;
}

