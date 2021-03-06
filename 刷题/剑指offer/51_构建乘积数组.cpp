
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) 
	{
		int helpnum = 1;
		vector<int> ret(A.size(), 0);
		for (int i = 0; i < A.size(); ++i)
		{
			ret[i] = helpnum;
			helpnum *= A[i];
		}
		helpnum = 1;
		for (int i = A.size() - 1; i >= 0; --i)
		{
			ret[i] *= helpnum;
			helpnum *= A[i];
		}
		return ret;
	}
};

//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1]
//其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

int main()
{
	vector<int> A = {1,2,3,4,1,2,3};
	Solution a;
	auto result = a.multiply(A);
	return 0;
}


