
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string PrintMinNumber(vector<int> numbers) 
	{
		if (numbers.empty())
		{
			return "";
		}
		sort(numbers.begin(), numbers.end(), Cmp);

		string result;
		for (auto num : numbers)
		{
			result += to_string(num);
		}
		return result;
	}

	static bool Cmp(int a, int b)
	{
		string stra = to_string(a);
		string strb = to_string(b);

		string strab = stra + strb;
		string strba = strb + stra;

		return strab < strba;
	}
};

// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{ 3，32，321 }，则打印出这三个数字能排成的最小数字为321323。

int main()
{
	vector<int> numbers = { 3,32,321 };
	Solution a;
	string str = a.PrintMinNumber(numbers);
	return 0;
}

