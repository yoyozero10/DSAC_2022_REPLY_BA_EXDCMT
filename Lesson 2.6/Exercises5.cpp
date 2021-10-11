/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

/**
 * 1. Cấu trúc con tối ưu: để đi đến tọa độ (m, n), đường đi sẽ phải qua một trong các ô
 * tọa độ (m-1, n-1), (m-1, n), (m, n-1). Do đó chi phí nhỏ nhất để đi đến (m, n) là chi
 * phí nhỏ nhất trong 3 ô trên cộng thêm chi phí tại ô (m, n).
 * 2. Vấn đề chồng lấn nhau của các bài toán con: việc tìm chi phí nhỏ nhất để đi đến ô
 * tọa độ (i, j) lặp đi lặp lại đến khi ta đến đích.
 */
 // chiến lược bottom-up
int findMinCost(int** cost, int m, int n) {
    int** result = new int* [m + 1]; // mảng lưu chi phí đi đến từng ô (i, j) với i <=m và j <= n
    for (int i = 0; i < m + 1; i++)
    {
        result[i] = new int[n + 1];
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

int main()
{
    int row, col;
    cout << "Nhap so hang, cot: ";
    cin >> row >> col;
    int** cost = new int* [row];
    for (int i = 0; i < row; i++)
    {
        cost[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Nhap gia tri tai vi tri [" << i << "][" << j << "]: ";
            cin >> cost[i][j];
        }
    }
    cout << "Nhap toa do dich(x, y): ";
    int x, y;
    cin >> x >> y;
    int minCost = findMinCost(cost, x, y);
    cout << "Chi phi nho nhat: " << minCost << endl;
    // thu hồi bộ nhớ
    for (int i = 0; i < row; i++)
    {
        delete[] cost[i];
    }
    delete[] cost;
}