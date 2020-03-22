#include <iostream>
#include <string>
using namespace std;

class Solution{
	public:
	int strStr(string haystack, string needle)
	{
		if (needle.empty())
		{
			return -1;
		}

		int next[needle.size()] = {0};

		for (int i = 1, j = 0; i + 1 < needle.size(); ++i)
		{
			while (j > 0 && needle[j] != needle[i])//回溯到第一个点或者相等的位置
			{
				j = next[j];
			}
			if (needle[j] == needle[i])//此处相等，可以求出下一个点的失配位置
			{
				j++;
				next[i + 1] = j;
			}
			
		}
		for ( int i = 0, j = 0; i< haystack.size(); ++i)
		{
			while (j > 0 && haystack[i] != needle[j])
			{
				j = next[j];
			}
			if (haystack[i] == needle[j])
			{
				j++;
			}
			if (j == needle.size())
			{
				return i - needle.size() + 1;
			}
		}
		return -1;
	}

};

/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2


示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	int ret =  a.strStr(std::string("aabaaabaaac"), std::string("aabaaac"));
	return 0;
}

