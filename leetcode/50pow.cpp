//
// Created by wangmin on 7/20/18.
//

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        bool is_neg = false;
        if(n < 0)
        {
            is_neg = true;
        }

        while(n)
        {
            if(n & 1){
                res *= x;
            }
            x *= x;
            n = n / 2;
        }
        return is_neg ? 1./res : res;

    }
};

void test1() {
    Solution s;
    std::cout <<  s.myPow(10.0, 5)<< std::endl;
    std::cout <<  s.myPow(10.0, -5)<< std::endl;
}
