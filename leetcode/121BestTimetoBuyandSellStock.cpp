//
// Created by wangmin on 7/26/18.
//
#include<vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
//    int maxProfit(vector<int>& prices) {
//        size_t n = prices.size();
//        if(n == 0)
//            return 0;
//
//        int l = prices[0];
//        int gain = 0;
//        for (int i = 1; i < n; ++i) {
//            if(prices[i] < l)
//            {
//                l = prices[i];
//            }
//
//            if(prices[i] - l > gain){
//                gain = prices[i] - l;
//            }
//        }
//        return gain;
//    }

    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        if(n == 0)
        {
            return 0;
        }
        vector<int> gain(n, 0);
        vector<int> f(n, 0);
        for (int i = 1; i < n; ++i) {
            gain[i] = prices[i] - prices[i - 1];
        }

        for (int j = 1; j < n; ++j) {
            f[j] = max(gain[j], gain[j] + f[j-1]);
        }

        return *std::max_element(f.begin(), f.end());
    }
};




TEST(MaxProfitTest, NonZero){
    vector<int> price = {7,1,5,3,6,4};
    Solution s;
    EXPECT_EQ(5, s.maxProfit(price));
}


