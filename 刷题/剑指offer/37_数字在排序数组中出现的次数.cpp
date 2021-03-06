
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k)
	{
		int start = 0, end = data.size() - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (data[mid] == k)
			{
				int left = start, right = mid;
				while (left < right)//第一个K
				{
					int tempmid = (left + right) >> 1;
					if (data[tempmid] == k)
					{
						right = tempmid;
					}
					else
					{
						left = tempmid + 1;
					}
				}
				int firstK = left;

				left = mid, right = end;
				while (left < right)//最后一个K
				{
					int tempmid = (left + right + 1) >> 1;
					if (data[tempmid] == k)
					{
						left = tempmid;
					}
					else
					{
						right = tempmid - 1;
					}
				}
				int lastK = left;

				return lastK - firstK + 1;
			}
			else if (data[mid] > k)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		return 0;
	}
};

//统计一个数字在排序数组中出现的次数。


int main()
{
	vector<int> data = {1, 2, 3, 4, 4, 4, 5, 6, 8, 10};
	Solution a;
	auto ret = a.GetNumberOfK(data, 4);
	return 0;
}


