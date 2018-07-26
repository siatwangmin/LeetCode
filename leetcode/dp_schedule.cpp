//
// Created by wangmin on 7/18/18.
//

class Solution {
public:
    int rec_schedule(vector<int>& value, vector<int>& prev, int opt)
    {
        if(opt == 0)
        {
            return value[opt];
        }
        int a = rec_schedule(value, prev, opt - 1);
        int b = value[opt] + rec_schedule(value, prev, prev[opt]);
        return a > b ? a : b;
    }

    int dp_schedule(vector<int>& value, vector<int>& prev, int opt)
    {
        int n = value.size();

        vector<int> opt_val(n);
        opt_val[0] = value[0];
        for (int i = 1; i <n; ++i) {
            int a = value[i] + opt_val[prev[i]];
            int b = opt_val[i - 1];
            opt_val[i] = a > b ? a : b;
        }
        return opt_val[opt];
    }
};

int test() {
    std::cout << "dynamic programming schedule test" << std::endl;
    vector<int> value;
    value.push_back(0);
    value.push_back(5);
    value.push_back(1);
    value.push_back(8);
    value.push_back(4);
    value.push_back(6);
    value.push_back(3);
    value.push_back(2);
    value.push_back(4);

    vector<int> prev;
    prev.push_back(0);
    prev.push_back(0);
    prev.push_back(0);
    prev.push_back(0);
    prev.push_back(1);
    prev.push_back(0);
    prev.push_back(2);
    prev.push_back(3);
    prev.push_back(5);

    Solution s;
    std::cout << s.rec_schedule(value, prev, 8) << std::endl;
    std::cout << s.dp_schedule(value, prev, 8) << std::endl;

    return 0;
}