
#include <iostream>

using namespace std;

class Solution {
public:
	double Power(double base, int exponent)
	{
		if (exponent < 0)
		{
			double ret = DoPower(base, -exponent);
			return 1.0 / ret;
		}
		else if(exponent == 0)
		{
			return 1;
		}
		else
		{
			return DoPower(base, exponent);
		}
	}

	double DoPower(double base, int exponent)
	{
		if (exponent == 1)
		{
			return base;
		}
		if (exponent & 1)//奇数
		{
			return base * DoPower(base, exponent / 2) * DoPower(base, exponent / 2);
		}
		else
		{
			return DoPower(base, exponent / 2) * DoPower(base, exponent / 2);
		}
	}
};

// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。 
// 保证base和exponent不同时为0 

int main()
{
	Solution a;
	auto ret = a.Power(2, -3);
	return 0;
}


