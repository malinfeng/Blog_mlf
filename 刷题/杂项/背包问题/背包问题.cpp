

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	return 0;
}


//01背包
//N个物品，背包容量是V
//i物品的体积vi，价值为wi


//二维动态规划的方案
//dp[i][j]  表示只看前i个物品，总体积消耗为j的情况下的总价值
//dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + w[i])
//对于i物品			不拿				拿

//初始化dp[0][0] = 0;
//递归方向j  0->V  i  0->N;

int ZeroOne_0(vector<int> &v, vector<int> &w, int V_sum)
{
	vector<vector<int> > dp(v.size() + 1, vector<int>(V_sum, 0));//物品与下标对应，防止越界检查

	for (int i = 1; i < v.size(); ++i)//第一个物品开始
	{
		for (int j = 0; j < V_sum; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
			}	
		}
	}

	return dp[v.size()][V_sum - 1];
}

//辅助空间压缩为一维，从大到小枚举！！！
//从大到小枚举，可以保证dp[j - v[i]]保存的是上一次的结果
int ZeroOne_1(vector<int> &v, vector<int> &w, int V_sum)
{
	vector<int> dp(V_sum, 0);//物品与下标对应，防止越界检查

	for (int i = 1; i < v.size(); ++i)//第一个物品开始
	{
		for (int j = V_sum; j >= v[i]; --j)//从大到小遍历，保证较小的dp记录的是上一次的状态
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}

	return dp[V_sum - 1];
}

//完全背包
//一维辅助空间。
//与01背包相比，每件物品可以选无限次

//dp[i]表示i容量下的最大价值
//
int Whole_0(vector<int> &v, vector<int> &w, int V_sum)
{
	vector<int> dp(V_sum, 0);//物品与下标对应，防止越界检查

	for (int i = 1; i < v.size(); ++i)//第一个物品开始
	{
		for (int j = V_sum; j >= v[i]; --j)//完全背包，一样从后往前遍历
		{
			for (int count = 0; count * v[i] <= j; ++count)//count表示第i个物品放多少个（依赖于前置状态）
			{
				dp[j] = max(dp[j], dp[j - count * v[i]] + count * w[i]);
			}
		}
	}

	return dp[V_sum - 1];
}

int Whole_1(vector<int> &v, vector<int> &w, int V_sum)
{
	vector<int> dp(V_sum, 0);//物品与下标对应，防止越界检查

	for (int i = 1; i < v.size(); ++i)//第一个物品开始
	{
		for (int j = v[i]; j <= V_sum; ++j)//完全背包，一样从前往后遍历，一个一个试往里面放i物品
		{
			dp[j] = max(dp[j], dp[j - v[i]] +  w[i]);
		}
	}

	return dp[V_sum - 1];
}

//多重背包

//N个物品，背包容量是V
//i物品的体积vi，价值为wi
//i物品最多为si件

//dp[i]表示i容量下的最大价值
//普通方法，O3  复杂度
int Multy_0(vector<int> &v, vector<int> &w,vector<int> &s, int V_sum)
{
	vector<int> dp(V_sum, 0);//物品与下标对应，防止越界检查

	for (int i = 1; i < v.size(); ++i)//第一个物品开始
	{
		for (int j = V_sum; j >= v[i]; --j)//从大到小遍历，保证较小的dp记录的是上一次的状态(01背包的扩展)
		{
			for (int k = 0; k < s[i] && k * v[i] <= j; ++k)//多重背包，数据上限有限制
			{
				dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
			}
		}
	}

	return dp[V_sum - 1];
}

//多重背包二进制优化，用二进制数来表示si的所有可能
//如  10 = 1 + 2 + 4 + 3; si 拆分成logsi个数字
int Multy_1(vector<int> &v, vector<int> &w, vector<int> &s, int V_sum)
{
	vector<int> dp(V_sum, 0);
	for (int i = 0; i < s.size(); ++i)//物品拆分，拆分成01背包问题
	{
		int j = 1;
		while (s[i] > j)//j个物品
		{
			v.push_back(j * v[i]);
			w.push_back(j * w[i]);
			s[i] -= j;
			j *= 2;
		}
		v.push_back(s[i] * v[i]);
		w.push_back(s[i] * w[i]);
	}

	for (int i = 1; i < v.size(); ++i)//第一个物品开始
	{
		for (int j = V_sum; j >= v[i]; --j)//从大到小遍历，保证较小的dp记录的是上一次的状态(01背包)
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}

	return dp[V_sum - 1];

}

//混合背包
//01背包、完全背包、多重背包的混合
//针对不同的类型，用不同的状态转移问题
//01背包正常，从小到达遍历，完全背包，从大到小遍历，多重背包则进行二进制分解。



//二维费用背包（两种限制的背包，可扩展成多维）


//分组背包，每组里面只能选一件，组内互斥
//即在决策时，每一个组，组内进行决策，即用一个for来决策求当前组内最优。


//背包问题的方案数


//求背包问题方案


//有依赖的背包问题，即物品有前置依赖项