//
// Created by wangmin on 7/18/18.
//

class Solution {
public:
    bool rec_check_sum(vector<int>& arr, int indx, int s)
    {
        if( s == 0)
        {
            return true;
        }
        else if(indx == 0)
        {
            return s == arr[0];
        }
        else if (arr[indx] > s)
        {
            return rec_check_sum(arr, indx - 1, s);
        }

        bool a = rec_check_sum(arr, indx - 1, s);
        bool b = rec_check_sum(arr, indx - 1, s - arr[indx]);
        bool c = a || b;
        return c;
    }

    bool dp_check_sum(vector<int>& arr, int indx, int s)
    {
        bool check_arr[indx + 1][s + 1];

        for (int i = 0; i < indx + 1; ++i) {
            check_arr[i][0] = true;
        }

        for (int j = 0; j < s + 1; ++j) {
            check_arr[0][j] = (arr[0] == j);
        }

        for (int m = 1; m < indx + 1; ++m) {
            for (int n = 1; n < s + 1; ++n) {
                if(arr[m] > s)
                {
                    check_arr[m][n] = check_arr[m-1][n];
                }
                else
                {
                    int a = check_arr[m - 1][n - arr[m]];
                    int b = check_arr[m-1][n];
                    check_arr[m][n] = a || b;
                }
            }
        }

        return check_arr[indx][s];


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
    std::cout << s.rec_check_sum(value, 5, 9) << std::endl;
    std::cout << s.rec_check_sum(value, 5, 10) << std::endl;
    std::cout << s.rec_check_sum(value, 5, 11) << std::endl;
    std::cout << s.rec_check_sum(value, 5, 12) << std::endl;
    std::cout << s.rec_check_sum(value, 5, 13) << std::endl;
    //std::cout << s.dp_no_neighbor_max_sum(value, 6) << std::endl;

    std::cout << s.dp_check_sum(value, 5, 9) << std::endl;
    std::cout << s.dp_check_sum(value, 5, 10) << std::endl;
    std::cout << s.dp_check_sum(value, 5, 11) << std::endl;
    std::cout << s.dp_check_sum(value, 5, 12) << std::endl;
    std::cout << s.dp_check_sum(value, 5, 13) << std::endl;
    return 0;
}
