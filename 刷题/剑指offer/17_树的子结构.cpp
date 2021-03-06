

#include <iostream>


struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution 
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
		{
			return false;
		}
		return IsSunTree(pRoot1, pRoot2)
			|| HasSubtree(pRoot1->left, pRoot2)
			|| HasSubtree(pRoot1->right, pRoot2);
	}

	//检测子树
	bool IsSunTree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr && pRoot2 != nullptr)
		{
			return false;
		}
		if ( pRoot2 == nullptr)
		{
			return true;
		}

		if (pRoot1->val == pRoot2->val)
		{
			return IsSunTree(pRoot1->left, pRoot2->left) && IsSunTree(pRoot1->right, pRoot2->right);
		}
		else
		{
			return false;
		}
	}
};

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
int main()
{
	TreeNode *testTree = new struct TreeNode(8);
	testTree->left = new struct TreeNode(8);
	testTree->right = new struct TreeNode(7);
	testTree->left->left = new struct TreeNode(9);
	testTree->left->right = new struct TreeNode(2);
	testTree->left->right->left = new struct TreeNode(4);
	testTree->left->right->right = new struct TreeNode(7);

	TreeNode *testSunTree = new struct TreeNode(8);
	testSunTree->left = new struct TreeNode(9);
	testSunTree->right = new struct TreeNode(2);

	//答案 1
	Solution a;
	auto ret = a.HasSubtree(testTree, testSunTree);
	return 0;
}

