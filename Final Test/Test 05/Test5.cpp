#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// khai báo nguyên mẫu hàm
void showResult(vector<int> resultList);
void findLIS(int* arr, int n);

int main()
{
    ifstream ifs("input5.txt");
    if (ifs) {
        int t;
        ifs >> t;
        int testCount = 1;
        while (t-- > 0) {
            int n;
            ifs >> n;
            int* arr = new int[n];
            for (int i = 0; i < n; i++) {
                ifs >> arr[i];
            }
            cout << "Test " << testCount++ << ": \n";
            findLIS(arr, n);
            delete[] arr;
        }
        ifs.close();
    }
    return 0;
}

/**
 * Phương thức tìm dãy con tăng dài nhất trong dãy cho trước
 *
 * @param arr dãy(mảng) đầu vào
 */
void findLIS(int* arr, int n) {
    // trường hợp cơ sở
    if (n == 0) {
        return;
    }
    // LIS[i] lưu trữ tập các phần tử tăng dần
    // arr[0…i] kết thúc với arr[i]
    vector<vector<int>> LIS(n, vector<int>{});
    
    // LIS[0] chứa danh sách các phần tử tăng dần kết thúc bởi arr[0]
    LIS[0].push_back(arr[0]);
    // bắt đầu từ vị trí phần tử thứ hai trong mảng
    for (int i = 1; i < n; i++) {
        // thực hiện cho tất cả các phần tử trước vị trí i
        for (int j = 0; j < i; j++) {
            // tìm chuỗi tăng liên tục kết thúc bởi phần tử arr[j]
            // trong đó arr[j] phải nhỏ hơn phần tử arr[i]
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size()) {
                LIS[i] = LIS[j];
            }
        }
        // bao gồm cả phần tử arr[i] vào danh sách thứ i của LIS
        LIS[i].push_back(arr[i]);
    }

    // resultIndex sẽ lưu trữ danh sách chứa kết quả dài nhất trong LIS
    int resultIndex = 0;
    for (int i = 0; i < n; i++) {
        if (LIS[resultIndex].size() < LIS[i].size()) {
            resultIndex = i;
        }
    }

    // hiển thị kết quả
    cout << LIS[resultIndex].size() << endl;
    showResult(LIS[resultIndex]);
}

void showResult(vector<int> resultList) {
    for (size_t i = 0; i < resultList.size(); i++) {
        cout << resultList[i] << ' ';
    }
    cout << endl;
}