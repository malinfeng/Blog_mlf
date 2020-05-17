#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	bool isMatch(string s, string p)
	{
		int i = 0, j = 0;
		int starposj = -1;//记录p中星星的位置
		int starposi = -1;//记录s中被星星匹配的位置
		while (i < s.size())
		{
			if (j < p.size() && (p[j] == s[i] || p[j] == '?'))	//正常匹配，都往前移动
			{
				i++;
				j++;
			}
			else if (j < p.size() && p[j] == '*')	//发现了星星
			{
				starposj = j;		//记录p中星星的位置
				j++;
				starposi = i;		//记录回溯位置，因为S之前都被有效匹配了，而此处不一定是被星星匹配
			}
			else if (starposj >= 0)	//匹配失败，并且存在星星，需要回溯，即startposi成功匹配一个
			{
				starposi++;			//
				i = starposi;		//i、j回溯
				j = starposj + 1;	//
			}
			else 
			{
				return false;
			}
		}
		while (j < p.size())
		{
			if (p[j] == '*')
			{
				j++;
			}
			else 
			{
				return false;
			}
		}
		return true;
	}
};

/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。

两个字符串完全匹配才算匹配成功。

说明:

	s 可能为空，且只包含从 a-z 的小写字母。
	p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。

示例 3:
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。


示例 4:
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".


示例 5:
输入:
s = "acdcb"
p = "a*c?b"
输入: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	string s("aaaa");
	string p("***a");
	auto ret = a.isMatch(s, p);
	return 0;
}
