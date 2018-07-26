//
// Created by wangmin on 7/20/18.
//
class Solution {
public:
    double sqrt(double x, double p) {
        if (x == 0) return 0;
        if (x < 0) return -NAN;
        double last = 0.0;
        double res = 1.0;
        while (abs((res - last)) > p)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return res;
    }
};

void test1() {
    Solution s;
    std::cout << s.sqrt(1000, 0.00000000001) << std::endl;
    std::cout << s.sqrt(1, 0.00000000001) << std::endl;
    std::cout << s.sqrt(-1, 0.00000000001) << std::endl;
}
