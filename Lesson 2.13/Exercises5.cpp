#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// hàm template nhập vào n phần tử của mảng
template<class T> void getInput(vector<T>& v) {
    int n;
    cout << "Nhap so phan tu cua vector: ";
    cin >> n;
    if (n > 0) {
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap phan tu thu " << (i + 1) << ": ";
            T x;
            cin >> x; 
            v.push_back(x);
        }
    }
    else {
        cout << "So phan tu phai la so duong.\n";
    }
}

// hàm hiển thị các phần tử của vector ra màn hình
template<class T> void showVectorElements(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

// hàm tìm giá trị nhỏ nhất trong vector
template<class T> T findMin(const vector<T>& v) {
    T min = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

template<class T> void findElementMaxK(vector<T>& v, int k) {
    sort(v.begin(), v.end(), greater<T>());
    int count = 1;
    for (size_t i = 0; i < v.size(); i++) {
        if (count == k) {
            cout << "Gia tri lon thu " << k << ": " << v[i] << endl;
            break;
        }
        if ((i + 1 < v.size()) && (v[i] != v[i + 1])) {
            count++;
        }
    }
    if (count < k) {
        cout << "Khong co phan tu lon thu " << k << endl;
    }
}

int main()
{
    vector<int> numbers;
    getInput(numbers);
    cout << "Cac phan tu trong vector: \n";
    showVectorElements(numbers);
    int k;
    cout << "Nhap k: ";
    cin >> k;
    findElementMaxK(numbers, k);
    return 0;
}