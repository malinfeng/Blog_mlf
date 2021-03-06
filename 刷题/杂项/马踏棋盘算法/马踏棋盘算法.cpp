
#include <iostream>
#include <vector>

using namespace std;

#define X_MAX 6
#define Y_MAX 6

vector<vector<int> > dirs = 
{
	{1, 2},
	{2, 1},
	{-1, -2},
	{-2, -1},
	{1, -2},
	{-2, 1},
	{-1, 2},
	{2, -1}
};

void PrintChess(vector<vector<int> > &chess)
{
	for (int i = 0; i < Y_MAX; ++i)
	{
		for (int j = 0; j < X_MAX; ++j)
		{
			if (chess[i][j] < 10)//补成两位数
			{
				std::cout << "0" << chess[i][j] << " ";
			}
			else
			{
				std::cout << chess[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << endl;
}


void TravelChess(vector<vector<int> > &chess, int curx, int cury, int count)
{
	if (count == X_MAX * Y_MAX)
	{
		PrintChess(chess);
	}

	if (chess[cury][curx] > 0)//已经走过了
	{
		return;
	}

	chess[cury][curx] = count;
	for (int i= 0; i < 8; ++i)//8个方向的尝试
	{
		int nextx = curx + dirs[i][0];
		int nexty = cury + dirs[i][1];
		if (nexty < 0 || nexty >= chess.size() || nextx < 0 || nextx >= chess[0].size())
		{
			continue;
		}
		TravelChess(chess, nextx, nexty, count + 1);
	}
	chess[cury][curx] = 0;//回溯的关键
}

//目前的解法用于求所有的输出结果，如果只用求一种结果则需要加上一个flag，用来标记结束
int main()
{
	vector<vector<int> > chess(Y_MAX, vector<int>(X_MAX, 0));

	TravelChess(chess, 0, 2, 1);
	
	return 0;
}
