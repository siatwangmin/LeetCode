#include "iostream"
#include "vector"

using namespace std;

//---------------------------------------------------------------------------------------------
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.
//---------------------------------------------------------------------------------------------

//这些算法都看着晕晕的，能理解它的思想，但是却又一些细节难以解决，定义好自己的问题
class Solution {
public:
	int findMin(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		while (nums[low] > nums[high])
		{
			int mid = (low + high) / 2;
			if(nums[low] > nums[mid])
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		return nums[low];
	}
};

class TestData
{
public:
	vector<int> GetTestData0()
	{
		vector<int> re;

		re.push_back(7);
		re.push_back(0);
		re.push_back(1);
		re.push_back(2);
		re.push_back(4);
		re.push_back(5);
		return re;
	}
	vector<int> GetTestData1()
	{
		vector<int> re;
		re.push_back(4);
		re.push_back(5);
		re.push_back(6);
		re.push_back(7);
		re.push_back(0);
		re.push_back(1);
		re.push_back(2);
		return re;
	}
};

class TestClass
{
public:
	void Test()
	{
		Solution mySolution = Solution();
		TestData testData = TestData();
		vector<int> data0 = testData.GetTestData0();
		cout << "data0 : " << mySolution.findMin(data0) << endl;

		vector<int> data1 = testData.GetTestData1();
		cout << "data1 : " << mySolution.findMin(data1) << endl;
	}
};