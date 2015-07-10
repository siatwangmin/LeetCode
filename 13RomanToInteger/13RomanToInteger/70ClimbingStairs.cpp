#include <iostream>
#include <vector>

using namespace std;

//Descirption*************************************************************************************
//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//*************************************************************************************************


//方法一：用递归的方法，Time Out
//class Solution {
//
//private:
//	int step1 = 1;
//	int step2 = 2;
//
//	int DPSolve(int n)
//	{
//		if (n <= 0)
//			return 0;
//		if (n == 1)
//		{
//			return step1;
//		}
//		if (n == 2)
//		{
//			return step2;
//		}
//
//		return DPSolve(n - 1) + DPSolve(n - 2);
//
//	}
//public:
//	int climbStairs(int n) {
//		return DPSolve(n);
//	}
//};

//方法二：用循环的方法
class Solution {
public:
	int climbStairs(int n) {
		vector<int> vec(n + 1, 0);
		if (n <= 0)
			return 0;
		vec[1] = 1;
		vec[2] = 2;

		for (int i = 3; i < n + 1; i++)
		{
			vec[i] = vec[i - 1] + vec[i - 2];
		}

		return vec[n];
	}
};