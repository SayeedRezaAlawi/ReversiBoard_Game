/*
 * ReversiBoard.cpp
 *
 *      Author: Sayeed Reza Alawi
 */
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#include "ReversiBoard.h"

CReversiBoard::CReversiBoard(int x, int y)
{
	FieldState = NotOccupied;
	m_sizex = x;
	int startPointx = (m_sizex / 2) - 1;
	m_sizey = y;
	int startPointy = (m_sizey / 2) - 1;

	// dynamically create array of pointers of size m_sizex
	m_fields = new field_s*[m_sizex];

	// dynamically allocate memory of size m_sizey for each row
	for (int i = 0; i < m_sizex; i++)
		m_fields[i] = new field_s[m_sizey];

	// assign values to allocated memory
	for (int i = 0; i < m_sizex; i++)
		for (int j = 0; j < m_sizey; j++)
			m_fields[i][j] = NotOccupied;

	m_fields[startPointx][startPointy] = Black;
	m_fields[startPointx][startPointy + 1] = White;
	m_fields[startPointx + 1][startPointy] = White;
	m_fields[startPointx + 1][startPointy + 1] = Black;

}

CReversiBoard::~CReversiBoard()
{
	delete[] m_fields;
}

void CReversiBoard::putPiece()
{
	switch (m_playerIndex)
	{
	case 1:

		cout
				<< "Player 1 (Black): please enter a Row and Column number according the depicted table"
				<< endl;
		while (1)
		{
			cin >> m_inputposition_x;
			if ((m_inputposition_x < 1) || (m_inputposition_x > 8))
			{
				cout
						<< " Player 1 (Black): You entered wrong Row number, please reenter your number "
						<< endl;
			}
			else
			{
				break;
			}
		}
		while (1)
		{
			cin >> m_inputposition_y;
			if ((m_inputposition_x < 1) || (m_inputposition_x > 8))
			{
				cout
						<< " Player 1 (Black): You entered wrong Column number, please reenter your number "
						<< endl;
			}
			else
			{
				break;
			}
		}

		if (getFieldState(m_inputposition_x, m_inputposition_y) == 0)
		{
			setFieldState(m_inputposition_x, m_inputposition_y, Black);
			boardScan();
			cout << string(50, '\n');

			m_playerIndex = 2;
		}
		else
		{
			cout
					<< " The position is already occupied, please reenter a new Row and Column number "
					<< endl;
		}
		break;
	case 2:
		cout
				<< "Player 2 (White): please enter a Row and Column number according the depicted table"
				<< endl;
		while (1)
		{
			cin >> m_inputposition_x;
			if ((m_inputposition_x < 1) || (m_inputposition_x > 8))
			{
				cout
						<< " Player 2 (White): You entered wrong Row number, please reenter your number "
						<< endl;
			}
			else
			{
				break;
			}
		}
		while (1)
		{
			cin >> m_inputposition_y;
			if ((m_inputposition_x < 1) || (m_inputposition_x > 8))
			{
				cout
						<< " Player 2 (White): You entered wrong Column number, please reenter your number "
						<< endl;
			}
			else
			{
				break;
			}

		}

		if (getFieldState(m_inputposition_x, m_inputposition_y) == 0)
		{
			setFieldState(m_inputposition_x, m_inputposition_y, White);
			boardScan();
			cout << string(50, '\n');

			m_playerIndex = 1;
		}
		else
		{
			cout
					<< " The position is already occupied, please reenter a new Row and Column number "
					<< endl;
		}
		break;
	}
}

void CReversiBoard::boardScan()
{
	switch (m_playerIndex)
	{
	case 1:
		if (m_inputposition_x == 1)
		{
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 1][m_inputposition_y]
							== White && m_inputposition_y < m_sizey - 1)
			{
				horizontalRightScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 1][m_inputposition_y - 2]
							== White && m_inputposition_y > 2)
			{
				horizontalLeftScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x][m_inputposition_y - 1]
							== White && m_inputposition_x < m_sizex - 1)
			{
				verticalDownScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x][m_inputposition_y] == White
					&& m_inputposition_x < m_sizex - 1
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightDownScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x][m_inputposition_y - 2]
							== White && m_inputposition_x < m_sizey - 1
					&& m_inputposition_y > 2)
			{
				diagonalLeftDownScan();
			}
			break;
		}
		////////////////////////////////////////////////
		else if (m_inputposition_x == 8)
		{
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 1][m_inputposition_y]
							== White && m_inputposition_y < m_sizey - 1)
			{
				horizontalRightScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 1][m_inputposition_y - 2]
							== White && m_inputposition_y > 2)
			{
				horizontalLeftScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 1]
							== White && m_inputposition_x > 2)
			{
				verticalUpScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 2][m_inputposition_y]
							== White && m_inputposition_x > 2
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightUpScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 2]
							== White && m_inputposition_x > 2
					&& m_inputposition_y > 2)
			{
				diagonalLeftUpScan();
			}

		}
		//////////////////////////////////////
		else
		{
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 1][m_inputposition_y]
							== White && m_inputposition_y < m_sizey - 1)
			{
				horizontalRightScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 1][m_inputposition_y - 2]
							== White && m_inputposition_y > 2)
			{
				horizontalLeftScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 1]
							== White && m_inputposition_x > 2)
			{
				verticalUpScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x][m_inputposition_y - 1]
							== White && m_inputposition_x < m_sizex - 1)
			{
				verticalDownScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 2][m_inputposition_y]
							== White && m_inputposition_x > 2
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightUpScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x][m_inputposition_y] == White
					&& m_inputposition_x < m_sizex - 1
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightDownScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 2]
							== White && m_inputposition_x > 2
					&& m_inputposition_y > 2)
			{
				diagonalLeftUpScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == Black
					&& m_fields[m_inputposition_x][m_inputposition_y - 2]
							== White && m_inputposition_x < m_sizey - 1
					&& m_inputposition_y > 2)
			{
				diagonalLeftDownScan();
			}
		}
		break;
		//////////////////////////////////////////////////

	case 2:
		if (m_inputposition_x == 1)
		{
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 1][m_inputposition_y]
							== Black && m_inputposition_y < m_sizey - 1)
			{
				horizontalRightScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 1][m_inputposition_y - 2]
							== Black && m_inputposition_y > 2)
			{
				horizontalLeftScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x][m_inputposition_y - 1]
							== Black && m_inputposition_x < m_sizex - 1)
			{
				verticalDownScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x][m_inputposition_y] == Black
					&& m_inputposition_x < m_sizex - 1
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightDownScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x][m_inputposition_y - 2]
							== Black && m_inputposition_x < m_sizey - 1
					&& m_inputposition_y > 2)
			{
				diagonalLeftDownScan();
			}
			break;
		}
		////////////////////////////////////////////////
		else if (m_inputposition_x == 8)
		{
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 1][m_inputposition_y]
							== Black && m_inputposition_y < m_sizey - 1)
			{
				horizontalRightScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 1][m_inputposition_y - 2]
							== Black && m_inputposition_y > 2)
			{
				horizontalLeftScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 1]
							== Black && m_inputposition_x > 2)
			{
				verticalUpScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 2][m_inputposition_y]
							== Black && m_inputposition_x > 2
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightUpScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 2]
							== Black && m_inputposition_x > 2
					&& m_inputposition_y > 2)
			{
				diagonalLeftUpScan();
			}

		}
		//////////////////////////////////////
		else
		{
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 1][m_inputposition_y]
							== Black && m_inputposition_y < m_sizey - 1)
			{
				horizontalRightScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 1][m_inputposition_y - 2]
							== Black && m_inputposition_y > 2)
			{
				horizontalLeftScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 1]
							== Black && m_inputposition_x > 2)
			{
				verticalUpScan();
			}

			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x][m_inputposition_y - 1]
							== Black && m_inputposition_x < m_sizex - 1)
			{
				verticalDownScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 2][m_inputposition_y]
							== Black && m_inputposition_x > 2
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightUpScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x][m_inputposition_y] == Black
					&& m_inputposition_x < m_sizex - 1
					&& m_inputposition_y < m_sizey - 1)
			{
				diagonalRightDownScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x - 2][m_inputposition_y - 2]
							== Black && m_inputposition_x > 2
					&& m_inputposition_y > 2)
			{
				diagonalLeftUpScan();
			}
			if (m_fields[m_inputposition_x - 1][m_inputposition_y - 1] == White
					&& m_fields[m_inputposition_x][m_inputposition_y - 2]
							== Black && m_inputposition_x < m_sizey - 1
					&& m_inputposition_y > 2)
			{
				diagonalLeftDownScan();
			}
		}
		break;
	}
}

void CReversiBoard::setFieldState(int x, int y, int FieldStatus)
{
	if (FieldStatus == 0)
	{
		m_fields[x - 1][y - 1] = NotOccupied;
	}
	if (FieldStatus == 1)
	{
		m_fields[x - 1][y - 1] = White;
	}
	if (FieldStatus == 2)
	{
		m_fields[x - 1][y - 1] = Black;
	}
}

void CReversiBoard::setPlayerScore(int player, int score)
{
	if (player == 1)
	{
		m_player1Score = score;
	}
	if (player == 2)
	{
		m_player2Score = score;
	}
}

unsigned short CReversiBoard::getBoardSizeX()
{
	return m_sizex;
}

unsigned short CReversiBoard::getBoardSizeY()
{
	return m_sizey;
}

unsigned short CReversiBoard::getFieldState(int x, int y)

{
	if (m_fields[x - 1][y - 1] == NotOccupied)
	{
		return 0;
	}
	else if (m_fields[x - 1][y - 1] == White)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

unsigned short CReversiBoard::getPlayerScore(int player)
{
	if (player == 1)
	{
		return m_player1Score;
	}
	if (player == 2)
	{
		return m_player2Score;
	}
	else
	{
		return 0;
	}
}

unsigned short CReversiBoard::getWiner()
{
	int totalscore = m_player1Score + m_player1Score;
	if (totalscore == 64)
	{
		if (m_player1Score > m_player2Score)
		{
			//cout << "Player 1 wins the Game" << endl;
			return m_playerIndex = 1;
		}
		else
		{
			//cout << "Player 2 wins the Game" << endl;
			return m_playerIndex = 2;
		}
	}
	else
	{
		return 0;
	}

}

void CReversiBoard::horizontalRightScan()
{
	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;

	// Right Side Horzental Scan
	switch (m_playerIndex)
	{
	case 1:
		// Right Side Horzental Scan Player 1
		if (m_fields[i][j + 1] == White && m_fields[i][j + 2] == Black)
		{
			m_fields[i][j + 1] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i][j + 1 + change] == White
						&& m_fields[i][j + 2 + change] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i][j + 2 + change - 1] == White
					&& m_fields[i][j + 2 + change] == Black)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i][j + 1 + w] = Black;
				}
			}
		}
		break;
		;
	case 2:
		// right Side Horzintal Scan Player 2
		if (m_fields[i][j + 1] == Black && m_fields[i][j + 2] == White)
		{
			m_fields[i][j + 1] = White;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i][j + 1 + change] == Black
						&& m_fields[i][j + 2 + change] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i][j + 2 + change - 1] == Black
					&& m_fields[i][j + 2 + change] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i][j + 1 + w] = White;
				}
			}
		}
		break;
	}

}

void CReversiBoard::horizontalLeftScan()
{
	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;
	// Left Side Horzental Scan
	switch (m_playerIndex)
	{
	case 1:
		// Left Side Horzental Scan Player 1
		if (m_fields[i][j - 1] == White && m_fields[i][j - 2] == Black)
		{
			m_fields[i][j - 1] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i][j - 1 - change] == White
						&& m_fields[i][j - 2 - change] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i][j - 2 - change + 1] == White
					&& m_fields[i][j - 2 - change] == Black)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i][j - 1 - w] = Black;
				}
			}
		}
		break;
		;
	case 2:
		// Left Side Horzintal Scan Player 2
		if (m_fields[i][j - 1] == Black && m_fields[i][j - 2] == White)
		{
			m_fields[i][j - 1] = White;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i][j - 1 - change] == Black
						&& m_fields[i][j - 2 - change] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i][j - 2 - change + 1] == Black
					&& m_fields[i][j - 2 - change] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i][j - 1 - w] = White;
				}
			}
		}
		break;
	}
}

void CReversiBoard::verticalUpScan()
{
	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;
	// Up Side Vertical Scan
	switch (m_playerIndex)
	{
	case 1:
		// Up Side Vertical Scan Player 1
		if (m_fields[i - 1][j] == White && m_fields[i - 2][j] == Black)
		{
			m_fields[i - 1][j] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i - 1 - change][j] == White
						&& m_fields[i - 2 - change][j] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i - 1 - change][j] == White
					&& m_fields[i - 2 - change][j] == Black)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i - 1 - w][j] = Black;
				}
			}
		}
		break;
	case 2:
		// Up Side Vertical Scan Player 2
		if (m_fields[i - 1][j] == Black && m_fields[i - 2][j] == White)
		{
			m_fields[i - 1][j] = White;
			break;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i - 1 - change][j] == Black
						&& m_fields[i - 2 - change][j] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i - 1 - change][j] == Black
					&& m_fields[i - 2 - change][j] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i - 1 - w][j] = White;
				}
			}
			break;
		}
		break;

	}
}

void CReversiBoard::verticalDownScan()
{
	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;
	// Down Side Vertical Scan
	switch (m_playerIndex)
	{
	case 1:
		// Down Side Vertical Scan Player 1
		if (m_fields[i + 1][j] == White && m_fields[i + 2][j] == Black)
		{
			m_fields[i + 1][j] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i + 1 + change][j] == White
						&& m_fields[i + 2 + change][j] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i + 1 + change][j] == White
					&& m_fields[i + 2 + change][j] == Black)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i + 1 + w][j] = Black;
				}
			}
		}
		break;
	case 2:
		// Down Side Vertical Scan Player 2
		if (m_fields[i + 1][j] == Black && m_fields[i + 2][j] == White)
		{
			m_fields[i + 1][j] = White;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i + 1 + change][j] == Black
						&& m_fields[i + 2 + change][j] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i + 1 + change][j] == Black
					&& m_fields[i + 2 + change][j] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i + 1 + w][j] = White;
				}
			}
		}
		break;
	}

}

void CReversiBoard::diagonalRightUpScan()
{
	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;
	// Right-Up Diaginal Scan Player 1
	switch (m_playerIndex)
	{
	case 1:
		if (m_fields[i - 1][j + 1] == White && m_fields[i - 2][j + 2] == Black)
		{
			m_fields[i - 1][j + 1] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i - 1 - change][j + 1 + change] == White
						&& m_fields[i - 2 - change][j + 2 + change] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i - 2 - change + 1][j + 2 + change - 1] == White
					&& m_fields[i - 2 - change][j + 2 + change] == Black)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i - 1 - w][j + 1 + w] = Black;
				}
			}
		}
		break;
		// Right-Up Diaginal Scan Player 2
	case 2:
		if (m_fields[i - 1][j + 1] == Black && m_fields[i - 2][j + 2] == White)
		{
			m_fields[i - 1][j + 1] = White;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i - 1 - change][j + 1 + change] == Black
						&& m_fields[i - 2 - change][j + 2 + change] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i - 2 - change + 1][j + 2 + change - 1] == Black
					&& m_fields[i - 2 - change][j + 2 + change] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i - 1 - w][j + 1 + w] = White;
				}
			}
		}
		break;
	}
}

void CReversiBoard::diagonalRightDownScan()
{
	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;
	// Right-Down Diaginal Scan Player 1
	switch (m_playerIndex)
	{
	case 1:
		if (m_fields[i + 1][j + 1] == White && m_fields[i + 2][j + 2] == Black)
		{
			m_fields[i + 1][j + 1] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i + 1 + change][j + 1 + change] == White
						&& m_fields[i + 2 + change][j + 2 + change] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i + 2 + change - 1][j + 2 + change - 1] == Black
					&& m_fields[i + 2 + change][j + 2 + change] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i + 1 + w][j + 1 + w] = Black;
				}
			}
		}
		break;

		// Right-Down Diaginal Scan Player 2
	case 2:
		flag = 0;
		change = 0;
		if (m_fields[i + 1][j + 1] == Black && m_fields[i + 2][j + 2] == White)
		{
			m_fields[i + 1][j + 1] = White;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i + 1 + change][j + 1 + change] == Black
						&& m_fields[i + 2 + change][j + 2 + change] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i + 2 + change - 1][j + 2 + change - 1] == Black
					&& m_fields[i + 2 + change][j + 2 + change] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i + 1 + w][j + 1 + w] = White;
				}
			}
		}
		break;
	}
}

void CReversiBoard::diagonalLeftUpScan()
{
	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;
	// Left-Up Diaginal Scan Player 1
	switch (m_playerIndex)
	{
	case 1:
		if (m_fields[i - 1][j - 1] == White && m_fields[i - 2][j - 2] == Black)
		{
			m_fields[i - 1][j - 1] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i - 1 - change][j - 1 - change] == White
						&& m_fields[i - 2 - change][j - 2 - change] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i - 2 - change + 1][j - 2 - change + 1] == White
					&& m_fields[i - 2 - change][j - 2 - change] == Black)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i - 1 - w][j - 1 - w] = Black;
				}
			}
		}
		break;
// Left-Up Diaginal Scan Player 2
	case 2:
		if (m_fields[i - 1][j - 1] == Black && m_fields[i - 2][j - 2] == White)
		{
			m_fields[i - 1][j - 1] = White;
		}
		else
		{
			while (flag == 0)
			{

				if (m_fields[i - 1 - change][j - 1 - change] == Black
						&& m_fields[i - 2 - change][j - 2 - change] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i - 2 - change + 1][j - 2 - change + 1] == Black
					&& m_fields[i - 2 - change][j - 2 - change] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i - 1 - w][j - 1 - w] = White;
				}
			}
		}
		break;
	}
}

void CReversiBoard::diagonalLeftDownScan()
{

	int i = m_inputposition_x - 1;
	int j = m_inputposition_y - 1;
	int flag = 0;
	int change = 0;
	// Left-Down Diaginal Scan Player 1
	switch (m_playerIndex)
	{
	case 1:
		if (m_fields[i + 1][j - 1] == White && m_fields[i + 2][j - 2] == Black)
		{
			m_fields[i + 1][j - 1] = Black;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i + 1 + change][j - 1 - change] == White
						&& m_fields[i + 2 + change][j - 2 - change] == White)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i + 2 + change - 1][j - 2 - change + 1] == White
					&& m_fields[i + 2 + change][j - 2 - change] == Black)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i + 1 + w][j - 1 - w] = Black;
				}
			}
		}
		break;
// Left-Down Diaginal Scan Player 2
	case 2:
		if (m_fields[i + 1][j - 1] == Black && m_fields[i + 2][j - 2] == White)
		{
			m_fields[i + 1][j - 1] = White;
		}
		else
		{
			while (flag == 0)
			{
				if (m_fields[i + 1 + change][j - 1 - change] == Black
						&& m_fields[i + 2 + change][j - 2 - change] == Black)
				{
					change++;
				}
				else
				{
					flag++;
				}
			}
			if (m_fields[i + 2 + change - 1][j - 1 - change] == Black
					&& m_fields[i + 2 + change][j - 2 - change] == White)
			{
				for (int w = 0; w <= change; w++)
				{
					m_fields[i + 1 + w][j - 1 - w] = White;
				}
			}
		}
		break;
	}
}

void CReversiBoard::print()
{
	int rows = m_sizex;
	int cols = m_sizey;

	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << "  ";
		for (int j = 0; j < cols; j++)
		{
			cout << m_fields[i][j] << endl;
			if (m_fields[i][j] == 0)
			{
				cout << " * ";
			}
			else if (m_fields[i][j] == 1)
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
	unsigned int m_player1Score = 0;
	unsigned int m_player2Score = 0;
	for (int i = 0; i < m_sizex; i++)
	{
		for (int j = 0; j < m_sizey; j++)
		{
			if (m_fields[i][j] == Black)
			{
				m_player1Score++;
			}
		}
	}
	cout << "Player 1(Black) Score is:" << m_player1Score << endl;
	for (int i = 0; i < m_sizex; i++)
	{
		for (int j = 0; j < m_sizey; j++)
		{
			if (m_fields[i][j] == White)
			{
				m_player2Score++;
			}
		}
	}
	cout << "Player 2(White) Score is:" << m_player2Score << endl;

}
