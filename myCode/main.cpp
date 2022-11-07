// Standard (system) header files

// Add more standard header files as required
#include <iostream>
#include <stdlib.h>
using namespace std;

// Add your project's header files here
#include "ReversiConsoleView.h"
#include "ReversiBoard.h"

// Main program
int main(void)
{
	cout << "Exercise 1.1 started." << endl << endl;
	CReversiBoard reversiboard(8, 8);
	CReversiConsoleView console(&reversiboard);
	console.print();
	int winner = 0;
	do
	{
		reversiboard.putPiece();
		console.print();
		winner = reversiboard.getWiner();
		if (winner == 1)
		{
			cout << "Player 1 wins the Game" << endl;
			break;
		}
		else if (winner == 2)
		{
			cout << "Player 2 wins the Game" << endl;
			break;
		}
	} while (winner == 0);

	return 0;
}
