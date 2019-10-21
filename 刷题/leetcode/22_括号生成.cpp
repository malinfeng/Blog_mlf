
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> ret;
		string curstr;
		dfs(curstr, n, n, n, ret);
		return ret;
	}
	void dfs(string curstr, int left, int right, int n, vector<string> & ret)
	{
		if (curstr.size() == 2*n)
		{
			ret.push_back(curstr);
			return;
		}
		if (left > right)
		{
			return;
		}
		if (left > 0)//先加左括号再加右括号
		{
			dfs(curstr + '(', left - 1, right, n, ret);
		}
		if (right > 0)
		{
			dfs(curstr + ')', left, right - 1, n, ret);
		}
	}
};

/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;
	auto ret = a.generateParenthesis(3);
	return 0;
}
