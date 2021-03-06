
#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
	int MoreThanHalfNum_Solution(std::vector<int> numbers)
	{
		int targetNum = 0, targetCount = 1;
		for (auto curnum : numbers)//找到疑似出现次数最多的数
		{
			if (curnum == targetNum)
			{
				targetCount++;
			}
			else//不是同一个数
			{
				targetCount--;
				if (targetCount == 0)
				{
					targetNum = curnum;
					targetCount = 1;
				}
			}
		}

		targetCount = 0;
		for (auto curnum : numbers)
		{
			if (curnum == targetNum)
			{
				targetCount++;
			}
		}
		if (targetCount > numbers.size() / 2)
		{
			return targetNum;
		}
		else
		{
			return 0;
		}
	}
};

// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
// 如果不存在则输出0。

int main()
{
	std::vector<int> nums = { 1,2,3,2,2,2,5,4,2 };
	Solution a;
	int result = a.MoreThanHalfNum_Solution(nums);
	return 0;
}

