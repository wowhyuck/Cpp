#include <iostream>
#include <iomanip>;
using namespace std;

// 오늘의 주제 : 연습문제

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

enum Dir
{
	Right,
	Down,
	Left,
	Up,
};

void PrintBoard();
void SetBoard();
void Play(int* xIdx, int* yIdx, int dir);


int main()
{
	cin >> N;

	SetBoard();
	PrintBoard();

	return 0;
}


void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

void SetBoard()
{
	int dir = 0;
	int limit = 2 * N - 1;
	int dir_count = 0;
	int count = 1;
	int num = N;
	int xIdx = 0;
	int yIdx = 0;

	while (dir_count < limit)
	{
		for (int i = 0; i < num; i++)
		{
			if (count != 1)
			{
				Play(&xIdx, &yIdx, dir);
				board[yIdx][xIdx] = count;
			}
			else
				board[0][0] = count;

			count++;
		}

		if (dir_count % 2 == 0)
			num--;

		dir_count++;
		dir++;
		dir %= 4;
	}
}

void Play(int* xIdx, int* yIdx, int dir)
{
	switch (dir)
	{
	case Right:
		(*xIdx)++;
		break;

	case Down:
		(*yIdx)++;
		break;

	case Left:
		(*xIdx)--;
		break;

	case Up:
		(*yIdx)--;
		break;
	}
}