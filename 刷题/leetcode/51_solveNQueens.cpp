#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
	vector<vector<string> > solveNQueens(int n)
	{
		vector<int> chess(n, -1);
		vector<vector<string> > ret;
		DFS(0, chess, ret);
		return ret;
	}
	void DFS(int row, vector<int>& chess, vector<vector<string>>& ret)
	{
		if (row == chess.size())
		{
			vector<string> oneret;
			for (int i = 0; i < chess.size(); ++i)
			{
				string line(chess.size(), '.');
				line[chess[i]] = 'Q';
				oneret.push_back(line);
			}
			ret.push_back(oneret);
			return;
		}

		for (int pos = 0; pos < chess.size(); ++pos)
		{
			if (posOk(row, pos, chess))
			{
				chess[row] = pos;
				DFS(row + 1, chess, ret);
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
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
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
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	auto ret = a.solveNQueens(4);
	return 0;
}
