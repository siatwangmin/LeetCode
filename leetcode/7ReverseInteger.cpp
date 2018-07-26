//
// Created by wangmin on 7/19/18.
//
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x)
        {
            res = res * 10 + (x % 10);
            x = x / 10;
            if(res > INT32_MAX || res < INT32_MIN ) {
                return 0;
            }
        }
        return res;

    }
};

int test1()
{
    Solution s;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(120) << std::endl;
    std::cout << s.reverse(1056389759) << std::endl;
    std::cout << s.reverse(INT32_MIN) << std::endl;
    std::cout << s.reverse(INT32_MAX) << std::endl;
}

