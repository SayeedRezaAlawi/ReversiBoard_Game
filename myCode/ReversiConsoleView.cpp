/*
 * ReversiConsoleView.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#include "ReversiConsoleView.h"

CReversiConsoleView::CReversiConsoleView(CReversiBoard *p)
{
	m_pReversiBoard = p;
}

void CReversiConsoleView::print()
{
	int player1score = 0;
	int player2score = 0;
	int rows = m_pReversiBoard->getBoardSizeX();
	int cols = m_pReversiBoard->getBoardSizeY();

	for (int i = 1; i < rows + 1; i++)
	{
		cout << i << "  ";
		for (int j = 1; j < cols + 1; j++)
		{

			if (m_pReversiBoard->getFieldState(i, j) == 0)
			{
				cout << " * ";
			}
			else if (m_pReversiBoard->getFieldState(i, j) == 1)
			{
				cout << " W ";
			}
			else
			{
				cout << " B ";
			}
		}
		cout << endl;
	}
	cout << "    ";
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << "  ";
	}
	cout << endl << endl;
	for (int i = 1; i < rows + 1; i++)
	{
		for (int j = 1; j < cols + 1; j++)
		{
			if (m_pReversiBoard->getFieldState(i, j) == 2)
			{
				player1score++;
			}
		}
	}
	m_pReversiBoard->setPlayerScore(1, player1score);
	cout << "Player 1(Black) Score is:" << m_pReversiBoard->getPlayerScore(1)
			<< endl;
	for (int i = 1; i < rows + 1; i++)
	{
		for (int j = 1; j < cols + 1; j++)
		{
			if (m_pReversiBoard->getFieldState(i, j) == 1)
			{
				player2score++;
			}
		}
	}
	m_pReversiBoard->setPlayerScore(2, player2score);
	cout << "Player 2(White) Score is:" << m_pReversiBoard->getPlayerScore(2)
			<< endl;
}
