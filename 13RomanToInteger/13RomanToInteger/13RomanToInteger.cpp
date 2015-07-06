#include <iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		int size = s.size();
		int preTemp = 0;
		for (int i = 0; i < size; i++)
		{
			int temp = 0;
			switch (s[i])
			{
			case 'M':
				temp = 1000;
				break;
			case 'D':
				temp = 500;
				break;
			case 'C':
				temp = 100;
				break;
			case 'L':
				temp = 50;
				break;
			case 'X':
				temp = 10;
				break;
			case 'V':
				temp = 5;
				break;
			case 'I':
				temp = 1;
				break;
			default:
				break; 
			}
			if (preTemp < temp)
			{
				result = result + temp - 2 * preTemp;
			}
			else
			{
				result = temp + result;
			}
			preTemp = temp;
		}
		return result;
	}
};

//int main()
//{
//	Solution mySolution = Solution();
//
//	cout << mySolution.romanToInt("DCXXI") << endl;
//	cout << mySolution.romanToInt("DCXIX") << endl;
//
//	getchar();
//	return 0;
//}