
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{

		vector<int> ret;
		if (k <= 0 || k > input.size())
		{
			return ret;
		}

		int left = 0;
		int right = input.size() - 1;
		int mid = Partition(input, left, right);
		while (mid != k - 1)
		{
			if (mid > k - 1)
			{
				right = mid - 1;
				mid = Partition(input, left, right);
			}
			else
			{
				left = mid + 1;
				mid = Partition(input, left, right);
			}
		}

		for (int i = 0; i < k; ++i)
		{
			ret.push_back(input.at(i));
		}
		return ret;
	}

	int Partition(vector<int> &input, int start, int end)
	{
		int midVal = input.at(end);
		int right = end - 1;
		while (start <= right)
		{
			while (start <= right && input.at(start) < midVal)
			{
				start++;
			}
			while (start <= right && input.at(right) >= midVal)
			{
				right--;
			}
			if (start < right)
			{
				std::swap(input.at(start), input.at(right));
			}
		}
		std::swap(input.at(start), input.at(end));
		return start;
	}
};

// 输入n个整数，找出其中最小的K个数。
// 例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字，则最小的4个数字是1, 2, 3, 4, 。

int main()
{
	vector<int> nums = { 0};
	Solution a;
	vector<int> result = a.GetLeastNumbers_Solution(nums,3);
	return 0;
}

