#include <vector>
#include <iostream>
#include <set>


using namespace std;

//*******************************************Description****************************************************
//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//**********************************************************************************************************

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		set<int> s;
		for (size_t i = 0; i < nums.size(); i++)
		{
			set<int>::iterator iter = s.find(nums[i]);
			if (iter == s.end())
			{
				s.insert(nums[i]);
			}
			else
			{
				s.erase(iter);
			}
		}
		set<int>::iterator result = s.begin();
		return *result;
	}
};