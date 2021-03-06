
#include <iostream>

using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == NULL)
		{
			return false;
		}
		bool hasE = false;
		bool hasDot = false;
		for (int i = 0; string[i] != '\0'; ++i)
		{
			if (string[i] == '+' || string[i] == '-')//第一个 - +
			{
				if (i == 0 || string[i - 1] == 'e' || string[i - 1] == 'E')
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			if (string[i] == '.')
			{
				if (hasDot)//两个点，错误
				{
					return false;
				}
                if (hasE)
                {
                    return false;
                }
				hasDot = true;
				continue;
			}
			if (string[i] == 'e' || string[i] == 'E')
			{
				if (hasE)//两个e
				{
					return false;
				}
				if (string[i + 1] == '\0')//e后面没数
				{
					return false;
				}
				hasE = true;
				continue;
			}
			if ('0' <= string[i] && string[i] <= '9')
			{
				continue;
			}
            else
            {
                return false;
            }
		}
		return true;
	}

};

//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
//但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

int main()
{
	char str[] = "12e+4.3";
	Solution a;
	auto result = a.isNumeric(str);
	return 0;
}


