#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int maxRob(vector<int> &nums)
	{
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> maxMoney;
		maxMoney = vector<int>(nums.size(), 0);

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
public:
	int rob(vector<int>& nums) {
		vector<int> sub1;
		vector<int> sub2;

		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];

		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			sub1.push_back(nums[i]);
		}
		for (size_t i = 1; i < nums.size(); i++)
		{
			sub2.push_back(nums[i]);
		}
		int temp1 = maxRob(sub1);
		int temp2 = maxRob(sub2);
		return temp1 > temp2 ? temp1 : temp2;
	}
};