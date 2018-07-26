//
// Created by wangmin on 7/16/18.
//
class Solution {
public:
    int rec_fib(int num) {
        if(num == 1 || num == 2)
            return 1;
        else
        {
            return rec_fib(num - 1) + rec_fib(num - 2);
        }
    }

    int dp_fib(int num)
    {
        if(num == 1 || num == 2)
            return 1;
        else
        {
            vector<int> vec(num);
            vec[0] = 1;
            vec[1] = 1;
            for (int i = 2; i < num; ++i) {
                vec[i] = vec[i-1] + vec[i -2];
            }
            return vec[num - 1];
        }

    }

};


