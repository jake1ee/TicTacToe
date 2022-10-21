#include <iostream>

using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

char current_marker = 'O';

bool win;

void DrawBoard()
{
	for (int i = 0; i < 3; i++)
	{
		cout << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << endl;
		if (i < 2)
			cout << "------" << endl;
	}
}

void placeMarker(int slot)
{
	int row, col;
	bool placed = false;
	do
	{
		row = slot / 3;
		col = (slot % 3) - 1;

		if (slot % 3 == 0)
		{
			row = row - 1;
			col = 2;
		}
		if (board[row][col] == 'O' || board[row][col] == 'X')
		{
			cout << "\nthis position alr filled please enter another position" << endl;
			cout << "Pos: ";
			cin >> slot;
			placed = true;
		}
	} while (placed);

	board[row][col] = current_marker;
	
	if (current_marker == 'O')
		current_marker = 'X';
	else
		current_marker = 'O';
}

char Winner()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{ 
			win = true;
			return board[i][0];
		}
			
		if (board[0][i] == board[1][i] && board[i][0] == board[2][i])
		{
			win = true;
			return board[0][i];
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		win = true;
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		win = true;
		return board[0][2];
	}

		return 0;
}

int main()
{
	char Win;
	while (!win)
	{
		int pos;

		DrawBoard();
		cout << endl;

		cout << "Current Player: " << current_marker << endl;
		cout << "Please Enter Position to put your maker: ";
		cin >> pos;

		placeMarker(pos);
		Win = Winner();
		system("cls");
	}
	DrawBoard();
	
	if (win == 0)
		cout << "DRAW ! ! !" << endl;
	else
		cout << "The winner is player " << win;

		return 0;
}