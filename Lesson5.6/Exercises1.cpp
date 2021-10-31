#include <iostream>
#include <queue>
using namespace std;

bool findX(queue<string> friends, string x) {
    while (!friends.empty()) {
        if (friends.front().compare(x) == 0) {
            return true;
        }
        friends.pop();
    }
    return false;
}

int main()
{
    queue<string> friends;
    // thêm phần tử mới vào hàng đợi
    friends.push("Huong");
    friends.push("Hoa");
    friends.push("Hien");
    friends.push("Ha");
    friends.push("Thanh");
    // kiểm tra hàng đợi có rỗng không
    cout << "Hang doi rong? " << boolalpha << friends.empty() << endl;
    // cho biết số phần tử hiện có trong hàng đợi
    cout << "So phan tu hien co trong hang doi: " << friends.size() << endl;
    // lấy phần tử đầu hàng đợi
    cout << "Phan tu dau hang doi: " << friends.front() << endl;
    // lấy phần tử cuối hàng đợi
    cout << "Phan tu cuoi hang doi: " << friends.back() << endl;
    // xóa phần tử đầu hàng đợi
    friends.pop(); // done
    // tìm kiếm phần tử x
    string x = "Mai";
    cout << x << " co ton tai trong hang doi? " << findX(friends, x) << endl;
    // hiển thị các phần tử hiện có trong hàng đợi
    while (!friends.empty()) {
        cout << friends.front() << "->";
        friends.pop();
    }
    cout << "null\n";
    // the end
    return 0;
}