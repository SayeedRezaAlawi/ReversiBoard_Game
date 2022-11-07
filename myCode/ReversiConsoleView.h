/*
 * ReversiConsoleView.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_
#include "ReversiBoard.h"

/**
 * Enables to print board state as output and shows the current score for each player.
 *
 */

class CReversiConsoleView
{
private:
	/**
	 * @param *m_pReversiBoard holds address of Reversi Board instance.
	 */
	CReversiBoard *m_pReversiBoard;
public:
	/**
	 * Receives a pointer from instance of Reversi Board class in order to
	 * access attributes and methods to provide an output.
	 */
	CReversiConsoleView(CReversiBoard *p);
	/**
	 * Provide an output of Reversi Board after each round with current score
	 * for each player and query user to put a new piece on the board.
	 */
	void print();
};

#endif /* REVERSICONSOLEVIEW_H_ */
