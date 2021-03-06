
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution 
{
public:
	std::vector<std::string> Permutation(std::string str)
	{
		if (str.empty())
		{
			return _result;
		}
		DoPermutation(str, 0);
		sort(_result.begin(), _result.end());
		return _result;
	}

	//求start往后的全排
	void DoPermutation(std::string &str, unsigned int start)
	{
		int size = str.length();
		if (start == size - 1)
		{
			_result.push_back(str);
			return;
		}

		for (int i = start; i < size; ++i)
		{
			if (i != start && str[i] == str[start])
			{
				continue;
			}
			std::swap(str[i], str[start]);
			DoPermutation(str, start + 1);
			std::swap(str[i], str[start]);//交换回来,回溯
		}
	}

	std::vector<std::string> _result;
};


// 输入一个字符串, 按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc, 则打印出由字符a, b, c所能排列出来的所有字符串abc, acb, bac, bca, cab和cba。

int main()
{
	std::string str("abc");
	Solution b;
	std::vector<std::string> result;
	result = b.Permutation(str);

	return 0;
}

