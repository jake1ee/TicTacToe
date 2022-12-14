#include <iostream>
using namespace std;

int index;
char board[9] = { '*','*', '*', '*', '*', '*', '*', '*', '*' };

int isFull()
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] != 'O')
		{
			if (board[i] != 'X')
				return 0;
		}
	}

	return 1;
}

int user_Won()
{
    for (int i = 0; i < 9; i += 3)
    {
        if ((board[i] == board[i + 1]) && (board[i + 1] == board[i + 2]) && (board[i] == 'O'))
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if ((board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]) && (board[i] == 'O'))
            return 1;
    }
    if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] == 'O'))
    {
        return 1;
    }
    if ((board[2] == board[4]) && (board[4] == board[6]) && (board[2] == 'O'))
    {
        return 1;
    }
    return 0;
}

int cpu_won()
{
    for (int i = 0; i < 9; i += 3)
    {
        if ((board[i] == board[i + 1]) && (board[i + 1] == board[i + 2]) && (board[i] == 'X'))
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if ((board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]) && (board[i] == 'X'))
            return 1;
    }
    if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] == 'X'))
    {
        return 1;
    }
    if ((board[2] == board[4]) && (board[4] == board[6]) && (board[2] == 'X'))
    {
        return 1;
    }
    return 0;
}

void DrawBoard()
{
    for (int i = 0; i < 9; i+=3)
    {
        cout << board[i] << "|" << board[i+1] << "|" << board[i+2] << endl;
        if (i <9)
            cout << "------" << endl;
    }
}

int minimax(bool flag)// The minimax function
{

    int max_val = -1000, min_val = 1000;
    int i, j, value = 1;
    if (cpu_won() == 1)
    {
        return 10;
    }
    else if (user_Won() == 1)
    {
        return -10;
    }
    else if (isFull() == 1)
    {
        return 0;
    }
    int score[9] = { 1,1,1,1,1,1,1,1,1 };//if score[i]=1 then it is empty

    for (i = 0; i < 9; i++)
    {
        if (board[i] == '*')
        {
            if (min_val > max_val) // reverse of pruning condition.....
            {
                if (flag == true)
                {
                    board[i] = 'X';
                    value = minimax(false);
                }
                else
                {
                    board[i] = 'O';
                    value = minimax(true);
                }
                board[i] = '*';
                score[i] = value;
            }
        }
    }

    if (flag == true)
    {
        max_val = -1000;
        for (j = 0; j < 9; j++)
        {
            if (score[j] > max_val && score[j] != 1)
            {
                max_val = score[j];
                index = j;
            }
        }
        return max_val;
    }
    if (flag == false)
    {
        min_val = 1000;
        for (j = 0; j < 9; j++)
        {
            if (score[j] < min_val && score[j] != 1)
            {
                min_val = score[j];
                index = j;
            }
        }
        return min_val;
    }
}