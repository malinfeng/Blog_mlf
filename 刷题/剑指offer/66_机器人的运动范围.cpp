
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold <= 0 || rows <= 0 || cols <= 0)
		{
			return 0;
		}
		int *mat = new int[rows * cols];

		IsOK(threshold, rows, cols, 0, 0, mat);

		int ret = 0;
		for (int i = 0; i < rows * cols; ++i)
		{
			if (mat[i] == 1)
			{
				ret++;
			}
		}
		return ret;
	}

	void IsOK(int threshold, int rows, int cols, int x, int y, int *mat)
	{
		if (x == rows || y == cols)
		{
			return;
		}
		int sum = 0;
		for (int i = x; i != 0; i = i / 10)
		{
			sum += i % 10;
		}
		for (int i = y; i != 0; i = i / 10)
		{
			sum += i % 10;
		}
		if (sum <= threshold)//xy可以,下一个位置
		{
			int index = y + x * cols;
			if (mat[index] == 1)//分支限界
			{
				return;
			}
			else
			{
				mat[index] = 1;
			}
			IsOK(threshold, rows, cols, x + 1, y, mat);
			IsOK(threshold, rows, cols, x, y + 1, mat);
		}
		else//不行直接返回
		{
			return;
		}
	}
};


// 地上有一个m行和n列的方格。
//一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
//但是不能进入行坐标和列坐标的数位之和大于k的格子。 
//例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
//但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
//请问该机器人能够达到多少个格子？

int main()
{
	return 0;
}
	


