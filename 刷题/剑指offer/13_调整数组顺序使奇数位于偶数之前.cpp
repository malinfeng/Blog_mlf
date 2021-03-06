
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array)
	{
		for (int i = 1; i < array.size(); ++i)//冒泡排序的思想
		{
			for (int j = i; j > 0; --j)
			{
				if (!(array[j - 1] & 1) && array[j] & 1)
				{
					swap(array[j - 1], array[j]);
				}
			}
		}
	}
};

// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
// 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
// 并保证奇数和奇数，偶数和偶数之间的相对位置不变。

int main()
{
	Solution a;
	vector<int > vec = { 1,2,3,4,5,6 };
	a.reOrderArray(vec);
	return 0;
}


