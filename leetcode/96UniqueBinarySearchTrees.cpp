#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	vector<int> vec;
public:
	int numTrees(int n) {
		if (n <= 0)
			return 0;	
		vec = vector<int>(n + 1, 0);
		vec[0] = 1;
		for (int i = 1; i < n + 1; i++)
			for (int j = 0; j < i; j++)
			{
				vec[i] += vec[i - 1 - j] * vec[j];
			}
		return vec[n];
	}
};