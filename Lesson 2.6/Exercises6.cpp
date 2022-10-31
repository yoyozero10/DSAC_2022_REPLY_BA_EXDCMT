/**
 * @file Exercises4.cpp
 * @author Branium Academy
 * @see https://braniumacademy.net
 * @brief Update exercises 4 lesson 2.6
 * @version 2.0
 * @date 2022-10-31
 *
 * @copyright Copyright (c) Branium Academy 2022
 *
 */
#include <iostream>
#include <cstring>
using namespace std;

int findLCS(const char*, const char*, int, int, int**);

// chiến lược top-down tìm chuỗi con chung dài nhất
// giả sử ta có chuỗi str1 gồm m phần tử, str2 gồm n phần tử và lcs(str1, str2) là độ dài chuỗi con chung
// dài nhất của str1, str2. Sau đây là các bước đệ quy để tìm độ dài chuỗi con chung tối đa:
// 1. Nếu kí tự cuối của hai chuỗi trùng nhau, tức là str1[m-1] == str2[n-1] thì
//      lcs(str1, str2) = 1+ lcs(str1[0,.., m-2], str2[0,...,n-2]);
// 2. Nếu kí tự cuối của hai chuỗi khác nhau thì
//      lcs(str1[0,..., m-1], str2[0,..., n-1]) = max(lcs(str1[0,...,m-2], str2[0,...,n-1]), str1[0,...,m-1], str2[0,...,n-2]));
// 
//                          lcs("AXYT", "AYZX")
//                            /              \
//              lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
//                 /       \                       /         \
// lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
// để tránh việc lặp lại tính toán, ta sử dụng mảng/vector lưu trữ kết quả tính toán từng bước
// sau đó tái sử dụng

int main()
{
    const char* str1 = "AGGTAB"; // tạo chuỗi str1
    const char* str2 = "GXTXAYB"; // tạo chuỗi str2
    int m = strlen(str1);
    int n = strlen(str2);
    // khai báo mảng lưu kết quả thực hiện từng bước
    int** table = new int*[m + 1];
    for (int i = 0; i < m + 1; i++) {
        table[i] = new int[n + 1]();
    }
    int result = findLCS(str1, str2, m, n, table);
    cout << "Do dai toi da chuoi con chung: " << result << endl;
    // giải phóng bộ nhớ
    for (int i = 0; i < m + 1; i++) {
        delete[] table[i];
    }
    delete[] table;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int findLCS(const char* str1, const char* str2, int m, int n, int** dp) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (str1[m - 1] == str2[n - 1]) {
        return dp[m][n] = 1 + findLCS(str1, str2, m - 1, n - 1, dp);
    }
    if (dp[m][n] != 0) {
        return dp[m][n];
    }
    return dp[m][n] = max(findLCS(str1, str2, m, n - 1, dp), findLCS(str1, str2, m-1, n, dp));
}