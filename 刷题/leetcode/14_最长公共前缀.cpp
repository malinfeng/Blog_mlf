#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		string ret;
		if (strs.empty())
		{
			return ret;
		}

		int pos = 0;
		while (1)
		{
			int start = 0;
			int end = strs.size() - 1;
			while (start <= end)
			{
				if (pos > strs[start].size() || pos > strs[end].size())
				{
					return strs[0].substr(0, pos);
				}
				if (strs[start][pos] != strs[end][pos])
				{
					return strs[0].substr(0, pos);
				}
				start++;
			}
			++pos;
		}
	}
};

/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"


示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。


说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	return 0;
}