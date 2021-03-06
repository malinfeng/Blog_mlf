
#include <iostream>

class Solution 
{
public:
	void replaceSpace(char *str, int length)//length为str的总长度，包括空余空间
	{
		int orglen = 0;
		int newlen = 0;
		int spaceCount = 0;
		for (int i = 0; str[i] != '\0'; ++i)
		{
			if (str[i] == ' ')
			{
				spaceCount++;
			}
			orglen++;
		}
		newlen = orglen + 2 * spaceCount;
		if (newlen > length)
		{
			return;
		}

		while (orglen >= 0)
		{
			if (str[orglen] == ' ')
			{
				str[newlen--] = '0';
				str[newlen--] = '2';
				str[newlen--] = '%';
			}
			else
			{
				str[newlen] = str[orglen];
				newlen--;
			}
			orglen--;
		}
	}
};

// 请实现一个函数，将一个字符串中的每个空格替换成“ %20”。
// 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

int main()
{
	Solution a;
	char *string = new char[50];
	string[0] = 'W';
	string[1] = 'e';
	string[2] = ' ';
	string[3] = 'A';
	string[4] = 'r';
	string[5] = 'e';
	string[6] = ' ';
	string[7] = 'H';
	string[8] = 'a';
	string[9] = 'p';
	string[10] = 'p';
	string[11] = 'y';
	string[12] = '\0';

	a.replaceSpace(string,50);
	return 0;
}

