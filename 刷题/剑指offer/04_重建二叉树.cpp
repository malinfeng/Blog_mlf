
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.size() != vin.size())
		{
			throw std::logic_error("error");
		}
		if (pre.empty() || vin.empty())
		{
			return nullptr;
		}
		return HelpReConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
	TreeNode* HelpReConstructBinaryTree(vector<int> &pre, int prestart, int preend, vector<int> &vin, int instart, int inend)
	{
		if (prestart > preend || instart > inend)
		{
			return NULL;
		}

		TreeNode* root = new TreeNode(pre[prestart]);
		int leftsize = 0;
		int i = instart;
		while (i <= inend)
		{
			if (vin[i] == root->val)
			{
				break;
			}
			leftsize++;
			++i;
		}
		if (i > inend)
		{
			throw std::logic_error("error");
		}
		root->left = HelpReConstructBinaryTree(pre, prestart + 1, prestart + leftsize, vin, instart, instart + leftsize - 1);
		root->right = HelpReConstructBinaryTree(pre, prestart + leftsize + 1, preend, vin, instart + leftsize + 1, inend);
		return root;
	}
};

// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建二叉树并返回。

int main()
{
	std::vector<int> pre = { 1,2,4,7,3,5,6,8 };
	std::vector<int> vin = { 4,7,2,1,5,3,8,6 };

	Solution a;
	TreeNode* root = nullptr;
	root = a.reConstructBinaryTree(pre, vin);
	return 0;
}

