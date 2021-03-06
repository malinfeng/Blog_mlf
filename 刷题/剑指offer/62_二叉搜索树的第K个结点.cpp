
#include <iostream>

using namespace std;

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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL)
		{
			return NULL;
		}
		TreeNode* pret = NULL;
		HelpKthNode(pRoot, pret, k);
		return pret;
	}

	void HelpKthNode(TreeNode* pRoot, TreeNode*& pret, int &k)
	{
		if (pRoot == NULL)
		{
			return;
		}
		if (k > 0)
		{
			HelpKthNode(pRoot->left, pret, k);
		}
		k--;
		if (k == 0)
		{
			pret = pRoot;
			return;
		}
		if (k > 0)
		{
			HelpKthNode(pRoot->right, pret, k);
		}
	}
};

//给定一棵二叉搜索树，请找出其中的第k小的结点。
//例如， （5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。


int main()
{
	Solution a;
	TreeNode *testTree = new struct TreeNode(5);
	testTree->left = new struct TreeNode(3);
	testTree->right = new struct TreeNode(7);
	testTree->left->left = new struct TreeNode(2);
	testTree->left->right = new struct TreeNode(4);
	testTree->right->left = new struct TreeNode(6);
	testTree->right->right = new struct TreeNode(8);

	TreeNode *result = a.KthNode(testTree, 3);

	return 0;
}