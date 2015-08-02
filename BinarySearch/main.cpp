#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
	vector<int> vec;
	int val;
	int BinarySearch(int start, int end )
	{
		if (start >= end)
		{
			return end;
		}
		int mid = start + (end - start) / 2;
		
		if (vec[mid] == val)
		{
			return mid;
		}
		else if (vec[mid] > val)
		{
			return BinarySearch(start, mid - 1);
		}
		else if (vec[mid] < val)
		{
			return BinarySearch(mid + 1, end);
		}
	}
public:
	//35 Search Insert Position
	//--------------------------------------------------------------------------
	//
	//Given a sorted array and a target value, return the index if the target is
	//found.If not, return the index where it would be if it were inserted in order.

	//	You may assume no duplicates in the array.

	//	Here are few examples.
	//	[1, 3, 5, 6], 5 ¡ú 2
	//	[1, 3, 5, 6], 2 ¡ú 1
	//	[1, 3, 5, 6], 7 ¡ú 4
	//	[1, 3, 5, 6], 0 ¡ú 0
	//
	//--------------------------------------------------------------------------
	int searchInsert(vector<int>& nums, int target) {
		vec = nums;
		val = target;
		int lo = 0;
		int offset = nums.size() - 1;
		int mid = offset / 2;
		

	}
};

int main()
{
	
	getchar();
	getchar();
	return 0;
}