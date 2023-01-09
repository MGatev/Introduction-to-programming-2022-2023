#include<iostream>
#include"Functions.h"

using namespace std;

//Constants declared in the header file

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

void CreateBoardBeforeStart(char myBoard[][MAX_SIZE], char playingBoard[][MAX_SIZE], const int boardSize)
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

void placeMines(int mines[][2], const int amountOfMines, char playingBoard[][MAX_SIZE], const int boardSize)
{
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

bool isValid(int row, int col, const int boardSize)
{
	//Checks if the given coordinates are valid
	if ((row >= 0 && row < boardSize) && (col >= 0 && col < boardSize))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isMine(int row, int col, char board[][MAX_SIZE])
{
	//Checks if on the given coordinates have a mine
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

void makeMove(int* x, int* y)
{
	// Take the input move
	printf("Enter your move, (row column): ");

	scanf_s("%d %d", x, y);
	return;
}

int main()
{
	int boardSize{}, amountOfMines{};

	InputValidation(boardSize, amountOfMines);

	char myBoard[MAX_SIZE][MAX_SIZE]{};

	char playingBoard[MAX_SIZE][MAX_SIZE]{};

	CreateBoardBeforeStart(myBoard, playingBoard, boardSize);

	printBoard(myBoard, boardSize);

	return 0;
}

