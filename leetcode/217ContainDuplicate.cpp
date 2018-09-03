#include <iostream>
#include <vector>
#include <set>

using namespace std;


//brute force O(n2)
//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		bool result = false;
//		for (size_t i = 0; i < nums.size(); i++)
//		{
//			for (size_t j = i + 1; j < nums.size(); j++)
//			{
//				if (nums[i] == nums[j])
//				{
//					result = true;
//					return result;
//				}
//			}
//		}
//		return result;
//	}
//};


class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> s;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (s.find(nums[i]) == s.end())
			{
				s.insert(nums[i]);
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

//int main()
//{
//
//	while (getchar())
//	{
//		Solution mySolution = Solution();
//		vector<int> numVect = vector<int>(5, 0);
//		for (vector<int>::iterator iter = numVect.begin(); iter != numVect.end(); iter++)
//		{
//			*iter = rand() % 20;
//			cout << *iter << '\t';
//		}
//		cout << endl;
//
//		if (mySolution.containsDuplicate(numVect))
//		{
//			cout << "True" << endl;
//		}
//		else
//		{
//			cout << "False" << endl;
//		}
//	}
//
//
//	getchar();
//	getchar();
//	return 0;
//
//	
//}