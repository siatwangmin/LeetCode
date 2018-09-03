#include<iostream>
#include <vector>

using namespace std;

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
class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		int low = 0;
		int high = nums.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				high = mid - 1;
			}
			else if (nums[mid] < target)
			{
				low = mid + 1;
			}
		}
		return low;
	}
};

class TestData
{
public:
	vector<int> GetTestData1()
	{
		vector<int> re;
		re.push_back(1);
		re.push_back(3);
		re.push_back(5);
		re.push_back(6);
		return re;
	}
	vector<int> GetTestData2()
	{
		vector<int> re;
		re.push_back(1);
		return re;
	}
	vector<int> GetTestData3()
	{
		std::vector<int> re;
		re.push_back(1);
		re.push_back(3);
		return re;
	}
};

class TestClass
{
public:
	void Test()
	{
		Solution mySolution = Solution();
		TestData test = TestData();
		vector<int> testdata = test.GetTestData1();
		vector<int> testdata2 = test.GetTestData2();
		vector<int> testdata3 = test.GetTestData3();
		cout << "result 0:" << mySolution.searchInsert(testdata, 5) << endl;
		cout << "result 1:" << mySolution.searchInsert(testdata, 2) << endl;
		cout << "result 2:" << mySolution.searchInsert(testdata, 7) << endl;
		cout << "result 3:" << mySolution.searchInsert(testdata, 0) << endl;
		cout << "result 4:" << mySolution.searchInsert(testdata2, 2) << endl;
		cout << "result 4:" << mySolution.searchInsert(testdata3, 3) << endl;
	}
};