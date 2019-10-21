
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) 
	{
		vector<int> dp(s.size(), 0);
		int ret = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (i > 0 && i - dp[i - 1] - 1 >= 0)
			{
				if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(')//判断本事是合法
				{
					dp[i] = dp[i - 1] + 2;
				}

				while (i - dp[i] >= 0 && dp[i - dp[i]] > 0)//该循环要仔细体会，表示与之相连的一直都大于0
				{
					dp[i] += dp[i - dp[i]];
				}
			}

			if (dp[i] > ret)
			{
				ret = dp[i];
			}
		}
		return ret;
	}
};

/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"


示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;
	auto ret = a.longestValidParentheses("()()");
	return 0;
}
