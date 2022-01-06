#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// khai báo hàm nguyên mẫu
template<class T> int findX(const vector<T>& v, T x);

class Pair {
    friend ostream& operator << (ostream&, const Pair&);
    string key;
    string value;

public:
    Pair(string key, string value) {
        this->key = key;
        this->value = value;
    }

    bool operator == (const Pair& other) const {
        return key == other.key;
    }

    void setKey(string key) {
        this->key = key;
    }

    void setValue(string value) {
        this->value = value;
    }

    string getKey() {
        return key;
    }

    string getValue() {
        return value;
    }
};

ostream& operator << (ostream& os, const Pair& p) {
    os << "[" << p.key << " - " << p.value << "]";
    return os;
}

// hàm template nhập vào n phần tử của mảng
template<class T> void getInput(vector<T>& v) {
    string key;
    string value;
    cout << "Nhap tu tieng Anh: ";
    cin >> key;
    cin.ignore();
    cout << "Nhap nghia tieng Viet: ";
    getline(cin, value);
    Pair pair(key, value);
    v.push_back(pair);
}

// hàm hiển thị các phần tử của vector ra màn hình
template<class T> void showVectorElements(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

// hàm hiển thị danh sách các key trong vector
void showKeys(vector<Pair>& v) {
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i].getKey() << endl;
    }
}

// hàm hiển thị danh sách các value trong vector
void showValues(vector<Pair>& v) {
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i].getValue() << endl;
    }
}

// hàm sửa nghĩa của từ
template<class T> void editValue(vector<T>& v) {
    string key;
    string value;
    cout << "Nhap tu tieng Anh can sua nghia: ";
    cin >> key;
    cin.ignore();
    Pair p(key, "");
    int index = findX(v, p);
    if (index != -1) {
        cout << "Nhap nghia moi cua tu: ";
        getline(cin, value);
        v[index].setValue(value);
    }
    else {
        cout << "Khong ton tai tu can update.\n";
    }
}

// hàm tìm x trong dictionary
template<class T> int findX(const vector<T>& v, T x) {
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

// hàm xóa cặp song ngữ
template<class T> void remove(vector<T>& v) {
    string key;
    cout << "Nhap tu tieng Anh can xoa: ";
    cin >> key;
    Pair p(key, "");
    int index = findX(v, p);
    if (index != -1) {
        v.erase(v.begin() + index);
    }
    else {
        cout << "Khong ton tai tu can xoa.\n";
    }
}

// hàm tìm cặp song ngữ
template<class T> void search(const vector<T>& v) {
    string key;
    cout << "Nhap tu tieng Anh can tim nghia: ";
    cin >> key;
    Pair p(key, "");
    int index = findX(v, p);
    if (index != -1) {
        cout << v[index] << endl;
    }
    else {
        cout << "Khong ton tai tu can tim.\n";
    }
}

int main()
{
    vector<Pair> dictionary;
    int choice;
    do {
        cout << "============== MENU ==============\n";
        cout << "1. Them cap song ngu moi.\n";
        cout << "2. Sua nghia tieng viet cua tu.\n";
        cout << "3. Xoa cap song ngu tieng Anh.\n";
        cout << "4. Tim nghia cua tu theo key.\n";
        cout << "5. Liet ke tat ca cap song ngu.\n";
        cout << "6. Liet ke cac keyword tieng Anh hien co.\n";
        cout << "7. Liet ke cac nghia tieng Viet hien co.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "Xin moi ban chon: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "<========= TAM BIET =========>\n";
            break;
        case 1:
            getInput(dictionary);
            break;
        case 2:
            editValue(dictionary);
            break;
        case 3:
            remove(dictionary);
            break;
        case 4:
            search(dictionary);
            break;
        case 5:
            cout << "Cac cap song ngu co trong tu dien:\n";
            showVectorElements(dictionary);
            break;
        case 6:
            cout << "Cac tu tieng Anh trong tu dien: \n";
            showKeys(dictionary);
            break;
        case 7:
            cout << "Cac nghia cua tu tieng Anh trong tu dien: \n";
            showValues(dictionary);
            break;
        default:
            cout << "Sai lua chon. Moi ban nhap lai!\n";
            break;
        }
    } while (choice != 0);
    return 0;
}