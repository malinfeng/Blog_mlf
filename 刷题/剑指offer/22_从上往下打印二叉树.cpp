
#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

using namespace std;

class Solution {
public:

	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		vector<int> result;
		queue<TreeNode*> que;
		if (root == NULL)
		{
			return result;
		}
		que.push(root);
		while(!que.empty())
		{
			TreeNode *pTempNode = que.front();
			que.pop();
			result.push_back(pTempNode->val);
			if (pTempNode->left != NULL)
			{
				que.push(pTempNode->left);
			}
			if (pTempNode->right != NULL)
			{
				que.push(pTempNode->right);
			}
		}
		return result;
	}

};

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

int main()
{
	TreeNode *testTree = new struct TreeNode(8);
	testTree->left = new struct TreeNode(8);
	testTree->right = new struct TreeNode(7);
	testTree->left->left = new struct TreeNode(9);
	testTree->left->right = new struct TreeNode(2);
	testTree->left->right->left = new struct TreeNode(4);
	testTree->left->right->right = new struct TreeNode(7);
	//正确答案  8879247
	Solution a;

	vector<int> vec = a.PrintFromTopToBottom(testTree);

	return 0;
}

