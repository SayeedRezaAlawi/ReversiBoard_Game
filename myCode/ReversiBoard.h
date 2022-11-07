/*
 * ReversiBoard.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CREVERSIBOARD_H_
#define CREVERSIBOARD_H_
#include <iostream>
#include <stdlib.h>
#include <string>
class CReversiConsoleView;
using namespace std;

/**
 * Creates a Reversi Game Board with size x=8 and size y=8
 * and let player to put a new piece on board. It scans the
 * board for increasing or decreasing players score. It also
 * provides each field state, players score.
 *
 */

class CReversiBoard
{
private:
	/**
	 * @param field_s define a enumeration type for field state.
	 */
	enum field_s
	{
		NotOccupied, White, Black,
	};
	/**
	 * @param **m_fields is a 2D dynamic memory and allocated to retain state on each
	 * field of board.
	 */
	field_s **m_fields;
	/**
	 * @param FieldState is enum type variable to
	 * store field state.
	 */
	field_s FieldState;
	/**
	 * @param m_sizex is used to store size x of board.
	 */
	unsigned short m_sizex;
	/**
	 * @param m_sizey is used to store size y of board.
	 */
	unsigned short m_sizey;
	/**
	 * @param m_playerIndex is used to store player index.
	 */
	unsigned short m_playerIndex = 1;
	/**
	 * @param m_player1Score retain player 1 score in each round.
	 */
	unsigned short m_player1Score = 0;
	/**
	 * @param m_player2Score holds player 2 score in each round.
	 */
	unsigned short m_player2Score = 0;
	/**
	 * @param m_inputposition_x retain x position of field which selected by each player.
	 */
	unsigned short m_inputposition_x = 0;
	/**
	 * @param m_inputposition_y holds y position of field which selected by each player.
	 */
	unsigned short m_inputposition_y = 0;
	/**
	 * Enables board scan in horizontal right side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void horizontalRightScan();
	/**
	 * Enables board scan in horizontal left side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void horizontalLeftScan();
	/**
	 * Enables board scan in vertical up side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void verticalUpScan();
	/**
	 * Enables board scan in vertical down side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void verticalDownScan();
	/**
	 * Enables board scan in diagonal right-up side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void diagonalRightUpScan();
	/**
	 * Enables board scan in diagonal right-down side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void diagonalRightDownScan();
	/**
	 * Enables board scan in diagonal left-up side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void diagonalLeftUpScan();
	/**
	 * Enables board scan in diagonal left-down side. It can only be called by boardScan method
	 * if some condition fulfilled.
	 */
	void diagonalLeftDownScan();

public:
	/**
	 * Constructor of CReversiBoard which allocate a 2D memory array
	 * to create board and hold each field state.
	 * @param x size of board in x direction.
	 * @param y size of board in y direction.
	 */
	CReversiBoard(int x, int y);
	/**
	 * Frees the allocated memory.
	 */
	~CReversiBoard();
	/**
	 * Enable player to put a new piece on the board.
	 */
	void putPiece();
	/**
	 * Scan board according different conditions and call different
	 * direction scan methods.
	 */
	void boardScan();
	/**
	 * Change the state of board after each round.
	 * @param x position of board in x direction which player want to put new piece.
	 * @param y position of board in y direction which player want to put new piece.
	 * @param FieldStatus type of piece which player wants to put in defined position
	 * on board.
	 */
	void setFieldState(int x, int y, int FieldStatus);
	/**
	 * Change the m_player1Score or m_player2Score variables after scanning board.
	 * @param player indicates the player index.
	 * @param score is current score of each player after scanning.
	 */
	void setPlayerScore(int player, int score);
	/**
	 * Returns the state of defined field by parameters x and y.
	 * @param x position of board in x direction which player wants to get the state.
	 * @param y position of board in y direction which player wants to get the state.
	 */
	unsigned short getFieldState(int x, int y);
	/**
	 * Returns player score of player index defined in parameter.
	 * @param player player index.
	 */
	unsigned short getPlayerScore(int player);
	/**
	 * Returns board size in X direction to print method
	 *  of Reversi Console View class.
	 */
	unsigned short getBoardSizeX();
	/**
	 * Returns board size in Y direction to print method
	 *  of Reversi Console View class.
	 */
	unsigned short getBoardSizeY();
	/**
	 * Returns winner player index if all pieces of board filled.
	 */
	unsigned short getWiner();
	/**
	 * Prints the board states in 2D direction view.
	 */
	void print();
};

#endif /* CREVERSIBOARD_H_ */
