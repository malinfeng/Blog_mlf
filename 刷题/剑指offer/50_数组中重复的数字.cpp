
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) 
	{
		for (int i = 0; i < length; ++i)
		{
			while(numbers[i] != i)
			{
				int actpos = numbers[i];
				if (0 <= actpos && actpos < length)
				{
					if (numbers[i] == numbers[actpos])
					{
						*duplication = numbers[i];
						return true;
					}
					swap(numbers[i], numbers[actpos]);
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
};

//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
//数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
//请找出数组中任意一个重复的数字。 
//例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

int main()
{
	int num[7] = {2,3,1,0,2,5,3};
	int *target = new int(0);
	Solution a;
	auto result = a.duplicate(num, 7, target);
	return 0;
}


