#include<iostream>
#include<cstdint>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n)
		{
			if (n & 0x01 == 1)
			{
				result++;
			}
			n = n >> 1;
		}
		return result;
	}
};

int main()
{
	Solution mySolution = Solution();
	int myInteger;
	while (cin >> myInteger)
	{
		cout << "The input number is : " << myInteger << endl;
		cout << "The Hamming Weight is : " << mySolution.hammingWeight(myInteger) << endl;
	}
	return 0;
}