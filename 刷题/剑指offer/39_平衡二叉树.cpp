
#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot)//使用后续遍历，每个节点只访问一次
	{
		int deep = 0;
		if (pRoot == NULL)
		{
			return false;
		}		
		return IsBalanced(pRoot, deep);

	}

	bool IsBalanced(TreeNode* pRoot,int &deep)
	{
		if (pRoot == nullptr)
		{
			deep = 0;
			return true;
		}
		int leftDeep = 0;
		int rightDeep = 0;
		if (IsBalanced(pRoot->left, leftDeep) && IsBalanced(pRoot->left, rightDeep))//左右子树都平衡
		{
			deep = leftDeep > rightDeep ? leftDeep + 1 : rightDeep + 1;
			if (leftDeep - rightDeep > 1 || leftDeep - rightDeep < -1)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

};

//输入一棵二叉树，判断该二叉树是否是平衡二叉树。

int main()
{
	TreeNode *testTree = new struct TreeNode(10);
	testTree->left = new struct TreeNode(4);
	testTree->right = new struct TreeNode(14);
	testTree->left->left = new struct TreeNode(2);
	testTree->left->right = new struct TreeNode(5);
	testTree->right->left = new struct TreeNode(11);
	testTree->right->right = new struct TreeNode(16);

	Solution a;
	bool result = a.IsBalanced_Solution(testTree);
	return 0;
}


