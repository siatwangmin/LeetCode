//
// Created by wangmin on 7/19/18.
//

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> pool(3, 0);

        size_t m = bills.size();
        for (int i = 0; i < m; ++i) {
            if(bills[i] == 5) {
                pool[0] += 1;
            }
            else if(bills[i] == 10) {
                pool[1] += 1;
            }
            else if(bills[i] == 20){
                pool[2] += 1;
            }
            int change = bills[i] - 5;
            int n_ten = change / 10;
            int n_five = (change - 10 * n_ten) / 5;

            if(pool[0] >= n_five){
                if(pool[1] >= n_ten)
                {
                    pool[0] -= n_five;
                    pool[1] -= n_ten;
                }
                else
                {
                    n_five += 2 * n_ten;
                    if(pool[0] >= n_five)
                    {
                        pool[0] -= n_five;
                    } else{
                        return false;
                    }
                }

            } else{
                return false;
            }

        }
        return true;
    }
};

void test1()
{
    std::cout << "Start Testing " <<std::endl;
    int arr[] = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    vector<int> bills(begin(arr), end(arr));;
//    bills.push_back(5);
//    bills.push_back(5);
//    bills.push_back(10);
    Solution s;
    std::cout << s.lemonadeChange(bills) <<std::endl;
    std::cout << "End Testing " <<std::endl;

}

void test2()
{
    std::cout << "Start Testing " <<std::endl;
    vector<int> bills;
    bills.push_back(5);
    bills.push_back(5);
    bills.push_back(5);
    bills.push_back(10);
    bills.push_back(20);
    Solution s;
    std::cout << s.lemonadeChange(bills) <<std::endl;
    std::cout << "End Testing " <<std::endl;
}

void test3()
{
    std::cout << "Start Testing " <<std::endl;
    vector<int> bills;
    bills.push_back(10);
    bills.push_back(10);
    Solution s;
    std::cout << s.lemonadeChange(bills) <<std::endl;
    std::cout << "End Testing " <<std::endl;
}

void test4()
{
    std::cout << "Start Testing " <<std::endl;
    vector<int> bills;
    bills.push_back(5);
    bills.push_back(5);
    bills.push_back(10);
    bills.push_back(10);
    bills.push_back(20);
    Solution s;
    std::cout << s.lemonadeChange(bills) <<std::endl;
    std::cout << "End Testing " <<std::endl;
}

