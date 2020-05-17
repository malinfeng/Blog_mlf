#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int totalNQueens(int n)
	{
		vector<int> chess(n, -1);
		int sum = 0;
		DFS(0, chess, sum);
		return sum;
	}
	void DFS(int row, vector<int>& chess, int& sum)
	{
		if (row == chess.size())
		{
			sum++;
			return;
		}

		for (int pos = 0; pos < chess.size(); ++pos)
		{
			if (posOk(row, pos, chess))
			{
				chess[row] = pos;
				DFS(row + 1, chess, sum);
				chess[row] = -1;
			}
		}
	}

	bool posOk(int row, int pos, vector<int>& chess)
	{
		for(int i = 0; i < chess.size(); ++i)
		{
			if (chess[i] >= 0 && chess[i] == pos)
			{
				return false;
			}
			if (chess[i] >= 0 && chess[i] + i == row + pos)
			{
				return false;
			}
			if (chess[i] >= 0 && row - pos == i - chess[i])
			{
				return false;
			}
		}
		return true;
	}
};

/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/