
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) 
	{
		if (s.empty())
		{
			return true;
		}
		stack<int> mys;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '[' || s[i] == '(' || s[i] == '{')
			{
				mys.push(i);
			}
			else
			{
				if (mys.empty())
				{
					return false;
				}
				else
				{
					if ((s[i] == ']' && s[mys.top()] == '[')
						|| (s[i] == '}' && s[mys.top()] == '{')
						|| (s[i] == ')' && s[mys.top()] == '('))
					{
						mys.pop();
					}
					else//错误情况
					{
						return false;
					}
				}
			}
		}
		if (mys.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：


	左括号必须用相同类型的右括号闭合。
	左括号必须以正确的顺序闭合。


注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true


示例 2:

输入: "()[]{}"
输出: true


示例 3:

输入: "(]"
输出: false


示例 4:

输入: "([)]"
输出: false


示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;

	auto ret = a.isValid("{[]}");
	return 0;
}
