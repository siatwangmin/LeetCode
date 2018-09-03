//
// Created by wangmin on 8/25/18.
//

#include <gtest/gtest.h>
#include <vector>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t m = cost.size();
        if(m < 2){
            return 0;
        }
        vector<int> res(cost);

        for (int i = 2; i < res.size(); ++i) {
            res[i] = min(res[i-1]+cost[i], res[i-2] + cost[i]);
        }
        return min(res[m-1], res[m-2]);

    }
};

TEST(MinCostClimbingTest, NullTest){
    Solution s;
    vector<int> vec;
    EXPECT_EQ(0,s.minCostClimbingStairs(vec));
}

TEST(MinCostClimbingTest, SimpleTest){
    Solution s;
    vector<int> vec= {10, 15, 20};
    EXPECT_EQ(15,s.minCostClimbingStairs(vec));
}


TEST(MinCostClimbingTest, ComplicateTest){
    Solution s;
    vector<int> vec = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    EXPECT_EQ(6,s.minCostClimbingStairs(vec));
}