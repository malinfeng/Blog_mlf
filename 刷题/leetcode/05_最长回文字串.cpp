
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	//中心扩散法，马拉车算法比较麻烦，目前没有实现
	string longestPalindrome(string s)
	{
		int maxLen = 0;
		int left = 0;
		int right = 0;
		int maxleft = 0;
		for (int i = 0; i < s.size(); i++)
		{
			left = i;
			right = i;
			while (right + 1 < s.size() && s[right + 1] == s[right])
			{
				right++;
			}
			while (left >= 0 && right < s.size() && s[left] == s[right])
			{
				left--;
				right++;
			}
			if (right - left - 1 > maxLen)
			{
				maxLen = right - left - 1;
				maxleft = left + 1;
			}
		}
		return s.substr(maxleft, maxLen);
	}
};

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。


示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{

	return 0;
}
