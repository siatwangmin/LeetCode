#include <iostream>
#include <vector>

using namespace std;

//方法一：动态规划，加递归，超时了
//class Solution {
//private:
//	vector<int> _nums;
//	int DPRecursiveRob(int indx)
//	{
//		int sum = 0;
//		if (indx >= _nums.size())
//			return sum;
//		sum = (DPRecursiveRob(indx + 1) > (DPRecursiveRob(indx + 2) + _nums[indx]) ?
//			DPRecursiveRob(indx + 1) : (DPRecursiveRob(indx + 2) + _nums[indx]));
//		return sum;
//	}
//
//public:
//	int rob(vector<int>& nums) {
//		_nums = nums;
//		return DPRecursiveRob(0);
//	}
//};

class Solution {
private:
	vector<int> maxMoney;
public:
	int rob(vector<int>& nums) {
		maxMoney = vector<int>(nums.size(), 0);
		
		if (nums.size() == 0)
		{
			return 0;
		}
		if (nums.size() == 1)
		{
			maxMoney[0] = nums[0];
		}
		if (nums.size() >= 2)
		{
			maxMoney[0] = nums[0];
			maxMoney[1] = nums[0] > nums[1] ? nums[0] : nums[1];
		}



		for (size_t i = 2; i < nums.size(); i++)
		{
			maxMoney[i] = (nums[i] + maxMoney[i - 2]) > maxMoney[i - 1] ? (nums[i] + maxMoney[i - 2]) : maxMoney[i - 1];
		}
		return maxMoney[nums.size() - 1];
	}
};