#include<iostream>
#include<vector>

using namespace std;


//*********************************************************Description****************************
//Given n non-negative integers representing an elevation map where the width of each bar is 1,
//compute how much water it is able to trap after raining.
//
//For example, 
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
//
//The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units
//of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//*****************************************************************************************************

//My Solution
class Solution {
public:
	int trap(vector<int>& height) {
		int result =0;
		int secondHeight = 0;
		vector<int> vec;
		if (height.size() == 0)
			return result;
		
		for (size_t i = 0; i < height.size(); i++)
		{
			if (vec.size() == 0 && height[i] != 0)
				vec.push_back(height[i]);
			else if (vec.size() != 0)
			{
				if (vec[0] <= height[i])
				{
					for (size_t j = 1; j < vec.size(); j++)
					{
						result += vec[0] - vec[j];
					}
					vec.clear();
				}
				vec.push_back(height[i]);
				if (vec[0] > height[i] && secondHeight < height[i])
				{
					secondHeight = height[i];
				}
			}
		}

		if (vec.size() > 2)
		{
			vec[0] = secondHeight;
			result += trap(vec);
		}
		return result;
	}
};


