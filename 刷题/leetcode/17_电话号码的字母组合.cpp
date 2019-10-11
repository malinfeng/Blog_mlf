
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution 
{
public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> ret;
		if (digits.empty())
		{
			return ret;
		}
		return helpfind(digits, 0);
	}

	vector<string> helpfind(string &digits, int start)
	{
		map<char, string> table{
		{'2',"abc"},
		{'3',"def"}, 
		{'4',"ghi"}, 
		{'5',"jkl"},
		{'6',"mno"}, 
		{'7',"pqrs"},
		{'8',"tuv"},
		{'9',"wxyz"}
		};
		if (start == digits.size() - 1)
		{
			vector<string> ret;
			string curstr = table[digits[start]];
			for (int i = 0; i < curstr.size(); ++i)
			{
				ret.push_back(string(1, curstr[i]));
			}
			return ret;
		}
		vector<string> oneret = helpfind(digits, start + 1);
		vector<string> ret;
		for (int i = 0; i < oneret.size(); ++i)
		{
			string curstr = table[digits[start]];
			for (int j = 0; j < curstr.size(); ++j)
			{
				ret.push_back(curstr[j] + oneret[i]);
			}
		}
		return ret;
	}
};

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;
	auto ret = a.letterCombinations("23");
	return 0;
}
