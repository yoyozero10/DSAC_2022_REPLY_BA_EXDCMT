#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// khai báo nguyên mẫu hàm
template<class T> void quickSort(T* arr, int leftIndex, int rightIndex);
template<class T> int partition(T* arr, int left, int right);
void showResult(string* words, int n);
int countX(string* arr, int n, string x);
int leftMostX(string* arr, int left, int right, string x);
int rightMostX(string* arr, int n, int left, int right, string x);

int main()
{
    ifstream ifs("input6.txt");
    if (ifs) {
        int t;
        ifs >> t;
        ifs.ignore();
        int testCount = 1;
        while (t-- > 0) {
            string x, str;
            string words[500];
            int numOfWord = 0;
            getline(ifs, x);
            getline(ifs, str);
            string word;
            stringstream ss(str);
            while (ss >> word) {
                words[numOfWord++] = word;
            }
            quickSort(words, 0, numOfWord - 1);
            cout << "Test " << testCount++ << ": \n";
            showResult(words, numOfWord);
            int occ = countX(words, numOfWord, x);
            cout << occ << endl;
        }
        ifs.close();
    }
    return 0;
}

// thuật toán sắp xếp quicksort
template<class T> void quickSort(T* arr, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int p = partition(arr, leftIndex, rightIndex);
        quickSort(arr, leftIndex, p - 1);
        quickSort(arr, p + 1, rightIndex);
    }
}
// phân mảnh và sắp xếp
template<class T> int partition(T* arr, int left, int right) {
    T pivot = arr[right];
    int i = left;
    for (int j = left; j <= right; j++) {
        if (arr[j] < pivot) {
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    T tmp = arr[i];
    arr[i] = arr[right];
    arr[right] = tmp;
    return i;
}

void showResult(string* words, int n) {
    for (int i = 0; i < n; i++) {
        cout << words[i] << ' ';
    }
    cout << endl;
}

int countX(string* arr, int n, string x) {
    int counter = 0;
    // tìm vị trí trái cùng xuất hiện x
    int startPos = leftMostX(arr, 0, n - 1, x);
    if (startPos == -1) { // không tìm thấy x
        return counter;
    }
    // tìm vị trí phải củng xuất hiện x
    int endPos = rightMostX(arr, n, 0, n - 1, x);
    return endPos - startPos + 1;
}

int leftMostX(string* arr, int left, int right, string x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) { // tìm phía bên phải
            return leftMostX(arr, mid + 1, right, x);
        }
        else { // tìm phía trái
            return leftMostX(arr, left, mid - 1, x);
        }
    }
    return -1;
}

int rightMostX(string* arr, int n, int left, int right, string x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x) {
            return mid;
        }
        if (arr[mid] <= x) { // tìm phía bên phải
            return rightMostX(arr, n, mid + 1, right, x);
        }
        else { // tìm phía trái
            return rightMostX(arr, n, left, mid - 1, x);
        }
    }
    return -1;
}