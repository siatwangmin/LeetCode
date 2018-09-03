//
// Created by wangmin on 7/31/18.
//

#include <vector>
#include <gtest/gtest.h>

using namespace std;

class SortSolution{
public:
    void BubbleSort0(vector<int>& arr){
        size_t n = arr.size();
        if(n < 1){
            return;
        }
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - 1; ++j) {
                if(arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    void BubbleSort1(vector<int>& arr){
        size_t n = arr.size();
        if(n < 1){
            return;
        }
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    void BubbleSort2(vector<int>& arr){
        size_t n = arr.size();
        if(n < 1){
            return;
        }
        for (int i = n - 1; i > 0; --i) {
            for (int j = i - 1; j > -1; --j) {
                if(arr[i] < arr[j]){
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    void InsertSort(vector<int>& arr){
        size_t n = arr.size();
        for (int i = 1; i < n; ++i) {
            if(arr[i] < arr[i-1]){
                int tmp = arr[i];
                int j = i;
                for (; tmp <= arr[j] && j > 0; --j) {
                    arr[j] = arr[j - 1];
                }
                arr[j] = tmp;
            }
        }

    }

    void SelectSort(vector<int>& arr){
        for (int i = 0; i < arr.size(); ++i) {
            int min = i;
            for (int j = i; j < arr.size(); ++j) {
                if(arr[min] > arr[j]){
                    min = j;
                }
            }
            swap(arr[min], arr[i]);
        }
    }

    int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int  i = low;
        for (int j = low; j < high; ++j) {
            if(arr[j] <= pivot){
                swap(arr[i++], arr[j]);
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    int partition2(int arr[], int low ,int high){
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        while(true){
            while(arr[i] < pivot){
                i++;

                if(i >= j){
                    break;
                }
            }
            while(arr[j] > pivot){
                j--;

                if(i >= j){
                    break;
                }
            }
            if(i >= j){
                break;
            }
            swap(arr[i], arr[j]);

        }
        swap(arr[low], arr[j]);
        return j;
    }

    void quicksort(int arr[], int low, int high){
        if(low < high){
            int pi = partition2(arr, low, high);

            quicksort(arr, low, pi - 1);
            quicksort(arr, pi+1, high);
        }
    }
};


TEST(SortSolutionTest, QuickSortTest){
    SortSolution s;
    int a[] = {5,4,3,2,1};
    s.quicksort(a, 0, 4);
//    size_t n = s.BubbleSort(a).size();
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(i + 1, a[i]) << "diff in " << i << std::endl;
    }
}
//
//TEST(SortSolutionTest, NULLSelectSortTest){
//    SortSolution s;
//    int a[0];
//    s.quicksort(a, 0, 0);
////    size_t n = s.BubbleSort(a).size();
//    for (int i = 0; i < 0; ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}


//TEST(SortSolutionTest, SelectSortTest){
//    SortSolution s;
//    vector<int> a = {5,4,3,2,1};
//    s.SelectSort(a);
////    size_t n = s.BubbleSort(a).size();
//    for (int i = 0; i < a.size(); ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}
//
//TEST(SortSolutionTest, NULLSelectSortTest){
//    SortSolution s;
//    vector<int> a;
//    s.SelectSort(a);
////    size_t n = s.BubbleSort(a).size();
//    for (int i = 0; i < a.size(); ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}





//TEST(SortSolutionTest, BubbleSort0Test){
//    SortSolution s;
//    vector<int> a = {5,4,3,2,1};
////    s.InsertSort(a);
//    s.BubbleSort0(a);
//    for (int i = 0; i < a.size(); ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}
//
//TEST(SortSolutionTest, InsertSortTest){
//    SortSolution s;
//    vector<int> a = {5,4,3,2,1};
//    s.InsertSort(a);
////    size_t n = s.BubbleSort(a).size();
//    for (int i = 0; i < a.size(); ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}
//
//TEST(SortSolutionTest, NULLInsertSortTest){
//    SortSolution s;
//    vector<int> a;
//    s.InsertSort(a);
////    size_t n = s.BubbleSort(a).size();
//    for (int i = 0; i < a.size(); ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}


//TEST(SortSolutionTest, BubbleSort1Test){
//    SortSolution s;
//    vector<int> a = {5,4,3,2,1};
//    s.BubbleSort1(a);
////    size_t n = s.BubbleSort(a).size();
//    for (int i = 0; i < a.size(); ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}
//
//TEST(SortSolutionTest, BubbleSort2Test){
//    SortSolution s;
//    vector<int> a = {5,4,3,2,1};
//    s.BubbleSort2(a);
////    size_t n = s.BubbleSort(a).size();
//    for (int i = 0; i < a.size(); ++i) {
//        EXPECT_EQ(i + 1, a[i]) << "diff in" << i << std::endl;
//    }
//}