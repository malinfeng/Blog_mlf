
#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

using namespace std;

class Solution 
{
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) //回溯法
	{
		vector<int> oneret;//某一种解
		vector<vector<int> > result;
		Travel(root, expectNumber, 0, oneret, result);
		return result;
	}

	void Travel(TreeNode* root, int expectNumber, int curSum, vector<int> &nodes, vector<vector<int> > &result)
	{
		if (!root)
		{
			return;
		}
		curSum += root->val;
		nodes.push_back(root->val);//回溯的要诀，push完了一定要pop不然不能完全回溯！！！

		if (curSum == expectNumber && root->left == nullptr && root->right == nullptr)
		{
			result.push_back(nodes); 
		}
		Travel(root->left, expectNumber, curSum, nodes, result);//每次进入一个新的Travel一定是能回溯到初始状态的！！
		Travel(root->right, expectNumber, curSum, nodes, result);
		nodes.pop_back();//回溯
	}
};

// 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)

int main()
{
	TreeNode *testTree = new struct TreeNode(10);
	testTree->left = new struct TreeNode(5);
	testTree->right = new struct TreeNode(12);
	testTree->left->left = new struct TreeNode(4);
	testTree->left->right = new struct TreeNode(7);

	vector<vector<int> > result;

	//正确答案  10 5 7          10 12
	Solution a;
	result = a.FindPath(testTree, 22);

	return 0;
}