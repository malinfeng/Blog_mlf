#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board)
	{
		bool solved = false;
		helpSolveSudoku(board, 0, 0, solved);
		return;
	}

	void helpSolveSudoku(vector<vector<char>>& board, int row, int column, bool& solved)
	{
		if (column == 9)
		{
			if (row == 8)
			{
				solved = true;
				return;
			}
			else
			{
				helpSolveSudoku(board, row + 1, 0, solved);
				return;
			}
		}
		char lastc = board[row][column];
		if (lastc == '.')
		{
			for (int i = 1; i < 10; ++i)
			{
				board[row][column] = '0' + i;
				if (valid(board, row, column))
				{
					helpSolveSudoku(board, row, column + 1, solved);
					if (solved)
					{
						return;
					}
				}
			}
			board[row][column] = lastc;
		}
		else
		{
			helpSolveSudoku(board, row, column + 1, solved);
			if (solved)
			{
				return;
			}
		}
	}

	bool valid(vector<vector<char>> & board, int row, int column)
	{
		int rowflag = 0;
		int colflag = 0;
		int blockflag = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (board[i][column] != '.')
			{
				if (rowflag & (1 << (board[i][column] - '0')))
				{
					return false;
				}
				rowflag |= (1 << (board[i][column] - '0'));
			}

			if (board[row][i] != '.')
			{
				if (colflag & (1 << (board[row][i] - '0')))
				{
					return false;
				}
				colflag |= (1 << (board[row][i] - '0'));
			}

			int newrow = row / 3 * 3 + i / 3;
			int newcol = column / 3 * 3 + i % 3;

			if (board[newrow][newcol] != '.')
			{
				if (blockflag & (1 << (board[newrow][newcol] - '0')))
				{
					return false;
				}
				blockflag |= (1 << (board[newrow][newcol] - '0'));
			}
		}

		return true;
	}
};

/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


空白格用 '.' 表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	vector<vector<char>> board = 
	{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'} 
	};

	a.solveSudoku(board );

	return 0;
}