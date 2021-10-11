#include <iostream>
#include <string>
using namespace std;

void showRevert(string str, int pos) {
    if (pos >= 0) { // điều kiện đệ quy
        cout << str.at(pos);
        showRevert(str, pos - 1);
    }
}

int main() {
    string str;
    cout << "Nhap vao chuoi ki tu: ";
    getline(cin, str);
    cout << "Chuoi ki tu dao nguoc: ";
    showRevert(str, str.length() - 1);

    return 0;
}