/**
 * @file Exercises4.cpp
 * @author Branium Academy
 * @see https://braniumacademy.net
 * @brief Update exercises 4 lesson 2.6
 * @version 2.0
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) Branium Academy 2022
 * 
 */
#include <iostream>
using namespace std;

const int ROW = 100;
const int COL = 100;

int findMinCost(int** cost, int m, int n);

/**
 * 1. Cấu trúc con tối ưu: để đi đến tọa độ (m, n), đường đi sẽ phải qua một trong các ô
 * tọa độ (m-1, n-1), (m-1, n), (m, n-1). Do đó chi phí nhỏ nhất để đi đến (m, n) là chi
 * phí nhỏ nhất trong 3 ô trên cộng thêm chi phí tại ô (m, n).
 * 2. Vấn đề chồng lấn nhau của các bài toán con: việc tìm chi phí nhỏ nhất để đi đến ô
 * tọa độ (i, j) lặp đi lặp lại đến khi ta đến đích.
 */

int main()
{
    int row, col;
    cout << "Nhap so hang, so cot cach nhau boi dau cach: " << endl;
    cin >> row >> col;
    int** cost = new int*[row];
    for (int i = 0; i < row; i++) {
        cost[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Nhap gia tri tai vi tri (" << i << ", " << j << "): ";
            cin >> cost[i][j];
        }
    }
    cout << "Nhap toa do o dich can di toi (x, y): " << endl;
    int x;
    int y;
    cin >> x >> y;
    int minCost = findMinCost(cost, x, y);
    cout << minCost << endl;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int findMinCost(int** cost, int m, int n) {
    int min(int a, int b); // khai báo nguyên mẫu hàm
    int** result;
    result = new int* [m + 1]; // mảng lưu chi phí đi đến từng ô (i, j) với i <= m và j <= n
    for (int i = 0; i < m + 1; i++) {
        result[i] = new int[n + 1]();
    }
    // gán giá trị cho phần tử đầu tiên trong result:
    result[0][0] = cost[0][0];
    // cập nhật hàng đầu tiên trong result:
    for (int i = 1; i <= n; i++) {
        result[0][i] = result[0][i - 1] + cost[0][i];
    }
    // cập nhật cột đầu tiên trong result:
    for (int i = 1; i <= m; i++) {
        result[i][0] = result[i - 1][0] + cost[i][0];
    }
    // cập nhật các phần tử ở các hàng khác:
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            result[i][j] = min(result[i - 1][j],
                min(result[i][j - 1], result[i - 1][j - 1])) + cost[i][j];
        }
    }
    return result[m][n];
}