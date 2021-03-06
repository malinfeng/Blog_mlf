
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	//最简单的使用map的方法
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
    {
        if(data.empty())
        {
            return;
        }
        std::map<int, int> tempmap;
        for(auto it : data)
        {
            tempmap[it]++;
        }
        int firstNum = 1;
        for(auto it = tempmap.begin();it != tempmap.end(); ++it)
        {
            if(it->second == 1 && firstNum)
            {
                *num1 = it->first;
                firstNum = 0;
            }
            else if(it->second == 1)
            {
                *num2 = it->first;
            }
        }
    }
};

//一个整型数组里除了两个数字之外，其他的数字都出现了两次。
//请写程序找出这两个只出现一次的数字。

int main()
{
	vector<int> data = { 1, 1, 5, 6, 5, 5, 5, 7 };
	int *num1 = new int(0), *num2 = new int(0);
	Solution a;
	a.FindNumsAppearOnce(data, num1, num2);
	return 0;
}


