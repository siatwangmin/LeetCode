//
// Created by wangmin on 7/18/18.
//

class Solution {
public:
    int rec_no_neighbor_max_sum(vector<int>& value, int indx)
    {
        if(indx == 0)
        {
            return value[indx];
        }
        else if(indx == 1)
        {
            return value[indx] > value[indx-1] ? value[indx] : value[indx - 1];
        }

        int a = rec_no_neighbor_max_sum(value, indx - 1);
        int b = value[indx] + rec_no_neighbor_max_sum(value, indx-2);
        return a > b ? a : b;
    }

    int dp_no_neighbor_max_sum(vector<int>& value, int indx)
    {
        size_t n = value.size();
        vector<int> opt(n);
        opt[0] = value[0];
        opt[1] = value[0] > value[1] ? value[0] : value[1];
        for (int i = 1; i < n; ++i) {
            int a = opt[i - 1];
            int b = opt[i - 2] + value[i];
            opt[i] = a > b ? a : b;
        }
        return opt[indx];
    }



};

int test1() {
    std::cout << "no neighbor max sum test1" << std::endl;
    vector<int> value;
    value.push_back(1);
    value.push_back(2);
    value.push_back(4);
    value.push_back(1);
    value.push_back(7);
    value.push_back(8);
    value.push_back(3);

    Solution s;
    std::cout << s.rec_no_neighbor_max_sum(value, 6) << std::endl;
    std::cout << s.dp_no_neighbor_max_sum(value, 6) << std::endl;
    return 0;
}

int test2() {
    std::cout << "no neighbor max sum test2" << std::endl;
    vector<int> value;
    value.push_back(4);
    value.push_back(1);
    value.push_back(1);
    value.push_back(9);
    value.push_back(1);

    Solution s;
    std::cout << s.rec_no_neighbor_max_sum(value, 4) << std::endl;
    std::cout << s.dp_no_neighbor_max_sum(value, 4) << std::endl;
    return 0;
}
