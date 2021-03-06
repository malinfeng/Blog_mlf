
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int StrToInt(string str)
	{
		int result = 0;
		int flag_ = 1;
		int i = 0;
		if (str[i] == '-')
		{
			flag_ = -1;
			i++;
		}
		else if (str[i] == '+')
		{
			i++;
		}
		while (i < str.size())
		{
			if ('0' <= str[i] && str[i] <= '9')
			{
				result = (result * 10 + (str[i] - '0'));
			}
			else
			{
				return 0;
			}
			i++;
		}
		result *= flag_;
		return result;
	}
};

//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)

int main()
{
	string num = "+2147483647";
	Solution a;
	auto result = a.StrToInt(num);
	return 0;
}


