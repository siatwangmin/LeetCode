//
// Created by wangmin on 8/25/18.
//
#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        size_t n = 0;
        if(m > 0){
            n = matrix[0].size();
        }

        for (int i = 0; i < m-1; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        }
        return true;
    }
};



TEST(ToeplitzMatrixTest, NULLTest){
    vector<vector<int>> mat;
    Solution s;
    EXPECT_NO_FATAL_FAILURE(s.isToeplitzMatrix(mat));
}

