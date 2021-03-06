
#include <iostream>
#include <queue>
#include <vector>

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
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int> > results;
		if (pRoot == NULL)
		{
			return results;
		}
		queue<TreeNode*> myq;
		myq.push(pRoot);
		int cursize = 1;
		int nextsize = 0;
		while (cursize)
		{
			vector<int> result;//一层的结果
			for (int i = 0; i < cursize; ++i)
			{
				TreeNode* curNode = myq.front();
				myq.pop();
				if (curNode->left)
				{
					myq.push(curNode->left);
					nextsize++;
				}
				if (curNode->right)
				{
					myq.push(curNode->right);
					nextsize++;
				}
				result.push_back(curNode->val);
			}
			cursize = nextsize;
			nextsize = 0;
			results.push_back(result);
		}
		return results;
	}
};

//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

// 用例:
// {8, 6, 10, 5, 7, 9, 11}
// 对应输出应该为:
// [[8], [6, 10], [5, 7, 9, 11]]


int main()
{
	Solution a;
	TreeNode *testTree = new struct TreeNode(8);
	testTree->left = new struct TreeNode(6);
	testTree->right = new struct TreeNode(10);
	testTree->left->left = new struct TreeNode(5);
	testTree->left->right = new struct TreeNode(7);
	testTree->right->left = new struct TreeNode(9);
	testTree->right->right = new struct TreeNode(11);
	
	vector<vector<int> > result = a.Print(testTree);

	return 0;
}
