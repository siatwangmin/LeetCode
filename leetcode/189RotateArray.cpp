//
// Created by wangmin on 7/20/18.
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
        while(k)
        {
            int tmp = nums[n - 1];
            for (int i = n - 1; i > 0; --i) {
                nums[i] = nums[i -1];
            }
            nums[0] = tmp;
            k--;
        }
    }

    void rotate1(vector<int>& nums, int k) {
        size_t n = nums.size();
        int step = k % n;
        vector<int> tmp(step);
        for (int j = 0; j < step; ++j) {
            tmp[j] = nums[n - (step - j)];
        }
        for (int i = n - 1; i > step - 1; --i) {
            nums[i] = nums[i - step];
        }

        for (int j = 0; j < step; ++j) {
            nums[j] = tmp[j];
        }
    }
};

