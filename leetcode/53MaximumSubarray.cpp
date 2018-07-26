//
// Created by wangmin on 7/26/18.
//
#include<vector>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> f(n, 0);
        f[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        }
        return *std::max_element(f.begin(), f.end());
    }
};

TEST(MaxProfitTest, NonZero){
    vector<int> price = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    EXPECT_EQ(6, s.maxSubArray(price));
}

TEST(MaxProfitTest, NULLTest){
    vector<int> price;
    Solution s;
    EXPECT_EQ(0, s.maxSubArray(price));
}





