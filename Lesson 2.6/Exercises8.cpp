/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

/**
 * th1: tập chứa phần tử cuối, tổng cần xét bằng tổng mục tiêu - giá trị phần tử cuối.
 * th2: tập không chứa phần tử cuối, tổng cần xét = tổng mục tiêu.
 */
bool isSubsetSum(bool** subset, int* set, int n, int sum) { // top-down
    if (sum == 0) { // nếu tổng == 0 -> true vì có 1 cách không chọn phần tử nào trong tập hợp
        return true;
    }
    if (n == 0) { // nếu n == 0 fase vì không thể tạo tổng sum từ 0 phần tử khi sum != 0
        return false;
    }
    if (subset[n - 1][sum]) { // nếu giá trị tại vị trí n đã được tính, trả về giá trị đó
        return subset[n - 1][sum];
    }
    if (set[n - 1] > sum) { // nếu giá trị cuối trong tập đang xét tại vị trí n-1 > tổng sum,
        return subset[n - 1][sum] = isSubsetSum(subset, set, n - 1, sum); // gọi đệ quy tính giá trị kế tiếp
    }
    // nếu không thỏa các điều kiện trên, tiếp tục đệ quy trong 2 trường hợp xét đến sự góp mặt
    // hoặc không có mặt của phần tử cuối tập đang xét tại vị trí n-1
    return subset[n - 1][sum] = isSubsetSum(subset, set, n - 1, sum) // không có mặt phần tử cuối tập đang xét
        || isSubsetSum(subset, set, n - 1, sum - set[n - 1]); // có mặt phần tử cuối tập đang xét
}

int main() {
    const int MAX = 2000;
    const int SIZE = 6;
    bool** subset = new bool* [MAX];
    for (int i = 0; i < MAX; i++)
    {
        subset[i] = new bool[MAX]();
    }
    int* set = new int[SIZE] { 3, 30, 1, 12, 5, 20 };
    cout << "Nhap tong can xet: ";
    int sum;
    cin >> sum;
    if (isSubsetSum(subset, set, SIZE, sum)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    // thu hồi bộ nhớ
    for (int i = 0; i < MAX; i++)
    {
        delete[] subset[i];
    }
    delete[] subset;
}