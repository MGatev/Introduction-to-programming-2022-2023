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
* <Main cpp file>
*
*/


#include<iostream>
#include "Functions.h"

using namespace std;

//Constants declared in the header file

//Function to print a message before the game starts
void PrintWelcomeMessage()
{
	printf("Welcome to the Minesweeper game!\n\n");
	printf("You win if you are able to reveal all non - mines cells and you lose if you open a mine.\n\n");
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
		printBoard(myBoard,  boardSize);

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

int main()
{
	int boardSize{}, amountOfMines{};

	InputValidation(boardSize, amountOfMines);

	playMinesweeper(boardSize, amountOfMines);

	return 0;
}

