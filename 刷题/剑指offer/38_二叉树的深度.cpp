
#include <iostream>
#include <algorithm>

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
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return 0;
		}
		else
		{
			return max(TreeDepth(pRoot->left) + 1, TreeDepth(pRoot->right) + 1);
		}
	}
};

//输入一棵二叉树，求该树的深度。
//从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

int main()
{
	TreeNode *pnode = new TreeNode(1);
	pnode->left = new TreeNode(2);
	pnode->left->left = new TreeNode(3);
	pnode->left->right = new TreeNode(3);
	Solution a;
	
	auto ret = a.TreeDepth(pnode);
	
	return 0;
}


