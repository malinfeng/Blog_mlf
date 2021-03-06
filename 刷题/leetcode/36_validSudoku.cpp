#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		vector<int> row(9, 0);
		vector<int> column(9, 0);
		vector<int> block(9, 0);

		for (int i = 0; i < 9; ++i)
		{
			for(int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
			       	int cmpnum = 1 << (board[i][j] - '0');
				
				if (row[i] & cmpnum)//row
				{
					return false;
				}
				row[i] |= cmpnum;

				if (column[j] & cmpnum)//cloumn
				{
					return false;
				}
				column[j] |= cmpnum;

				int blockidx = i / 3 * 3 + j / 3;//block
				if (block[blockidx] & cmpnum)
				{
					return false;
				}
				block[blockidx] |= cmpnum; 
			}
		}
		return true;
	}
};
/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。


	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true


示例 2:

输入:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{



	return 0;
}
