//
// Created by wangmin on 7/19/18.
//

class Solution {
public:
    double rec_coints(vector<double>& head, int m, int n)
    {
        if(n > m)
        {
            return 0.0;
        }
        if(n == 1 && m == 1)
        {
            return head[0];
        }
        if (n == 0 )
        {
            double res = 1.0;
            for (int i = 0; i < m; ++i) {
                res *= (1.0 - head[i]);
            }
            return res;
        }
        return rec_coints(head, m - 1, n - 1) * head[m - 1] + rec_coints(head,m - 1, n) * (1.0 - head[m - 1]);
    }

    double dp_coins(vector<double>& head, int n)
    {
        size_t m = head.size();
        vector<double> tail(m);
        for (int i = 0; i < m; ++i) {
            tail[i] = 1.0 - head[i];
        }

        double dp[m][n + 1];
        dp[0][0] = tail[0];
        dp[0][1] = head[0];

        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] * tail[i];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if(j > i + 1)
                {
                    dp[i][j] = 0.0;
                } else{
                    dp[i][j] = head[i] * dp[i - 1][j - 1] + tail[i] * dp[i - 1][j];
                }

            }
        }

        return dp[m - 1][n];


    }

};

int test1() {
    std::cout << "Testing Start....." << std::endl;
    int n = 9;
    vector<double> p(n);

    for (int i = 0; i < n; ++i) {
        p[i] = 0.1 + i * 0.1;
    }

    Solution s;

    for (int k = 0; k < n + 1; ++k) {
        std::cout << s.dp_coins(p, k) << std::endl;
        std::cout << s.rec_coints(p, n, k) << std::endl;
    }

    std::cout << "Testing End....." << std::endl;
    return 0;
}

int test2() {
    return 0;
}

