
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution 
{
public:
	int FirstNotRepeatingChar(string str) 
	{
		std::map<char, int> map;
		for (auto it: str)
		{
			if (map[it])
			{
				map[it]++;
			}
			else
			{
				map[it] = 1;
			}
		}
		for (int i = 0; i < str.size();++i)
		{
			if (map[str[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

// 在一个字符串(0 <= 字符串长度 <= 10000，全部由字母组成)
// 中找到第一个只出现一次的字符, 并返回它的位置, 如果没有则返回 - 1（需要区分大小写）

int main()
{
	string str = "sadfghjasdfg";//正确答案为5
	Solution a;
	int result = a.FirstNotRepeatingChar(str);
	return 0;
}


