#include <iostream>
#include <vector>

using namespace std;

//方法一：动态规划，加递归，超时了
class Solution {
private:
	vector<int> _nums;
	int DPRecursiveRob(int indx)
	{
		int sum = 0;
		if (indx >= _nums.size())
			return sum;
		sum = (DPRecursiveRob(indx + 1) > (DPRecursiveRob(indx + 2) + _nums[indx]) ?
			DPRecursiveRob(indx + 1) : (DPRecursiveRob(indx + 2) + _nums[indx]));
		return sum;
	}

public:
	int rob(vector<int>& nums) {
		_nums = nums;
		return DPRecursiveRob(0);
	}
};