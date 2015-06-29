#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		bool result = false;
		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] == nums[j])
				{
					result = true;
					return result;
				}
			}
		}
		return result;
	}
};

int main()
{

	while (getchar())
	{
		Solution mySolution = Solution();
		vector<int> numVect = vector<int>(5, 0);
		for (vector<int>::iterator iter = numVect.begin(); iter != numVect.end(); iter++)
		{
			*iter = rand() % 20;
			cout << *iter << '\t';
		}
		cout << endl;

		if (mySolution.containsDuplicate(numVect))
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
	}


	getchar();
	getchar();
	return 0;

	
}