
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		vector<int> result;
		if (array.empty())
		{
			return result;
		}
		int left = 0, right = array.size() - 1;
		int minX = 65535;
		while (left < right)
		{
			if (array[left] + array[right] == sum)
			{
				if (array[left]*array[right] < minX)
				{
					minX = array[left] * array[right];
					result.clear();
					result.push_back(array[left]);
					result.push_back(array[right]);
				}
				right--;
			}
			else if (array[left] + array[right] < sum)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		return result;
	}
};

//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
//如果有多对数字的和等于S，输出两个数的乘积最小的。

//对应每个测试案例，输出两个数，小的先输出。

int main()
{
	vector<int> array = {1, 4, 5, 6, 8, 10};
	Solution a;
	auto result = a.FindNumbersWithSum(array, 9);
	return 0;
}


