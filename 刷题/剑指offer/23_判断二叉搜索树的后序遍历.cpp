
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool VerifySquenceOfBST(vector<int> sequence) 
	{
		if (sequence.empty())
		{
			return false;
		}
		return HelpVerifySquenceOfBST(sequence, 0, sequence.size() - 1);
	}

	bool HelpVerifySquenceOfBST(vector<int> &sequence, int left, int right)
	{
		if (right <= left)//NULL或者一个节点
		{
			return true;
		}
		int rootval = sequence[right];

		//确定左子树
		int midpos = left;
		while (midpos < right)
		{
			if (sequence[midpos] > rootval)
			{
				break;
			}
			midpos++;
		}
		//检验右子树
		int i = midpos;
		while (i < right)
		{
			if (sequence[i] < rootval)
			{
				return false;//右子树出现小的节点，直接返回错误
			}
			i++;
		}

		return HelpVerifySquenceOfBST(sequence, left, midpos - 1) 
			&& HelpVerifySquenceOfBST(sequence, midpos, right - 1);
	}
};

// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。

//4, 8, 6, 12, 16, 14, 10  true
//7, 4, 5, 6  false
int main()
{
	Solution a;
	vector<int> nums = { 7, 4, 5, 6 };
	bool b = a.VerifySquenceOfBST(nums);

	system("pause");
}

