#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/**
     * Phương thức dùng để hiển thị ma trận xoắn ốc cấp m x n.
     * B1: khởi tạo các biến rowStart-chỉ số hàng đầu, rowEnd-chỉ số hàng cuối,
     * colStart-cột đầu, colEnd-cột cuối.
     * B2: Lặp chừng nào tất cả các cạnh cấu thành ma trận xoắn ốc được duyệt:
     * B2.1: in ra hàng đầu tiên trong vùng đang xét của ma trận, tăng rowStart lên 1.
     * B2.2: in ra cột cuối cùng trong vùng đang xét của ma trận, giảm colEnd đi 1.
     * B2.3: in ra hàng cuối cùng trong vùng đang xét của ma trận, giảm rowEnd đi 1.
     * B2.4: in ra cột đầu tiên trong vùng đang xét của ma trận, tăng colStart lên 1.
     *
     * @param a        ma trận kết quả cấp m x n
     * @param rowStart vị trí hàng bắt đầu của lần duyệt hiện tại
     * @param rowEnd   vị trí hàng cuối của lần duyệt hiện tại
     * @param colStart vị trí cột bắt đầu của lần duyệt hiện tại
     * @param colEnd   vị trí hàng cột cuối của lần duyệt hiện tại
     */
void printSpiralForm(int** a, int rowStart, int rowEnd,
    int colStart, int colEnd) {
    if (rowStart >= rowEnd || colStart >= colEnd) {
        return; // điểm dừng
    }
    // gán giá trị cho hàng đầu trong số các hàng còn lại
    for (int i = colStart; i < colEnd; ++i) { // c
        cout << a[rowStart][i] <<  " ";
    }
    rowStart++; // chuyển đến hàng kế tiếp ở lần duyệt tới
    // gán giá trị cho cột cuối trong số các cột còn lại
    for (int i = rowStart; i < rowEnd; ++i) {
        cout << a[i][colEnd - 1] << " ";
    }
    colEnd--; // chuyển tới cột liền trước ở lần duyệt tới
    // gán giá trị cho hàng cuối trong các hàng còn lại
    if (rowStart < rowEnd) {
        for (int i = colEnd - 1; i >= colStart; --i) {
            cout << a[rowEnd - 1][i] << " ";
        }
        rowEnd--; // chuyển tới hàng liền trước ở lần duyệt tới
    }
    // gán giá trị cho cột đầu trong số các cột còn lại
    if (colStart < colEnd) {
        for (int i = rowEnd - 1; i >= rowStart; --i) {
            cout << a[i][colStart] << " ";
        }
        colStart++; // chuyển đến cột kế tiếp ở lần duyệt tới
    }
    printSpiralForm(a, rowStart, rowEnd, colStart, colEnd);
}

int main() {
    int row, col;
    string inputFile = "input13.1.txt";
    string inputFile2 = "input13.2.txt";
    ifstream ifs(inputFile2);
    // đọc input từ file

    if (ifs) {
        ifs >> row >> col;
        int** arr = new int* [row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[row];
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ifs >> arr[i][j];
            }
        }
        // hiển thị kết quả theo dạng ma trận xoắn ốc
        int rowEnd = row;
        int colEnd = col;
        int rowStart = 0, colStart = 0;
        /*  rowStart - starting row index
            rowEnd - ending row index
            colStart - starting column index
            colEnd - ending column index
        */
        printSpiralForm(arr, rowStart, rowEnd, colStart, colEnd);

        ifs.close();
        // thu hồi bộ nhớ
        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    else {
        cout << "Khong mo duoc file";
    }

    return 0;
}