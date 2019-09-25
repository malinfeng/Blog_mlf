
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) 
    {
		if (array.empty() || array[0].empty())
		{
			return false;
		}
        int row = array.size() - 1;
        int colu = 0;
        while(row >= 0 && colu < array[0].size())
        {
            if (array[row][colu] == target)
            {
                return true;
            }
            else if (array[row][colu] < target)
            {
                ++colu;
            }
            else 
            {
                --row;
            }
        }
        return false;
    }
};


int main()
{
	Solution a;

	vector<vector<int> > array = 
	{	{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15}
	};

	auto ret = a.Find(7, array);

	return 0;
}

