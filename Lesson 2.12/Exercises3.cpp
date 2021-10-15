/**
 * @author Branium Academy
 * @version 2021.10
 * @see <a href="https://braniumacademy.net/">...</a>
 */
#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100;

void showWords(array<string, MAX_SIZE>& words, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << words[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        int n = 0;
        string str;
        getline(cin, str);
        stringstream ss(str);
        string word;
        array<string, MAX_SIZE> words;
        while (ss >> word) { // đọc từng từ và lưu vào mảng
            words[n++] = word;
        }
        sort(words.begin(), words.begin() + n);// sử dụng hàm sắp xếp có trong thư viện
        showWords(words, n); // gọi hàm hiển thị kết quả
    }
}
