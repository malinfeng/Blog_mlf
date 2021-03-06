
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		if (rotateArray.empty())
		{
			return 0;
		}

		int left = 0;
		int right = rotateArray.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;

			if (rotateArray[mid] < rotateArray[right])//因为是查找最小的数，所以不能跳过mid的数字
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return rotateArray[right];
	}
};

// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
// 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
// 例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。 
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。


int main()
{
	Solution a;
	vector<int> vec = { 3,4,5,1,2 };
	int b = a.minNumberInRotateArray(vec);
	return 0;
}


