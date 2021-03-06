

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	void Mirror(TreeNode *pRoot)
	{
		if (pRoot == NULL)
		{
			return;
		}
		swap(pRoot->left, pRoot->right);
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

//操作给定的二叉树，将其变换为源二叉树的镜像。
int main()
{
	TreeNode *testTree = new struct TreeNode(1);
	testTree->left = new struct TreeNode(3);
	testTree->right = new struct TreeNode(4);

	Solution a;
	a.Mirror(testTree);
	return 0;
}

