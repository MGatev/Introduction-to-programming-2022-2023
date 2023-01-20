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
* <Function to start the game>
*
*/

#include<iostream>
#include "Initialise.h"
#include "PlayGame.h"

//Constants declared in the header file

int main()
{
	int boardSize{}, amountOfMines{};

	InputValidation(boardSize, amountOfMines);

	playMinesweeper(boardSize, amountOfMines);

	return 0;
}

