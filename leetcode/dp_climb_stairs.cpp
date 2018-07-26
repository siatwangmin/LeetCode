//
// Created by wangmin on 7/18/18.
//

class Solution {
public:
    int rec_climb_stair(int n)
    {
        if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }
        return rec_climb_stair(n - 1) + rec_climb_stair(n - 2);

    }

    int dp_climb_stair(int n)
    {
        vector<int> val(n + 1);
        val[0] = 1;
        val[1] = 1;
        val[2] = 2;
        for (int i = 3; i < n + 1; ++i) {
            val[i] = val[i - 1] + val[i - 2];
        }
        return val[n];
    }

};

int test1() {
    std::cout << "check sum" << std::endl;
    vector<int> value;
    value.push_back(3);
    value.push_back(34);
    value.push_back(4);
    value.push_back(12);
    value.push_back(5);
    value.push_back(2);

    Solution s;
    std::cout << s.rec_climb_stair(1) << std::endl;
    std::cout << s.rec_climb_stair(2) << std::endl;
    std::cout << s.rec_climb_stair(3) << std::endl;
    std::cout << s.rec_climb_stair(4) << std::endl;
    std::cout << s.rec_climb_stair(5) << std::endl;
    std::cout << s.rec_climb_stair(6) << std::endl;
    std::cout << s.rec_climb_stair(7) << std::endl;
    std::cout << s.rec_climb_stair(8) << std::endl;
    //std::cout << s.dp_no_neighbor_max_sum(value, 6) << std::endl;

    std::cout << s.dp_climb_stair(1) << std::endl;
    std::cout << s.dp_climb_stair(2) << std::endl;
    std::cout << s.dp_climb_stair(3) << std::endl;
    std::cout << s.dp_climb_stair(4) << std::endl;
    std::cout << s.dp_climb_stair(5) << std::endl;
    std::cout << s.dp_climb_stair(6) << std::endl;
    std::cout << s.dp_climb_stair(7) << std::endl;
    std::cout << s.dp_climb_stair(8) << std::endl;
    return 0;
}

int test2() {
    return 0;
}
