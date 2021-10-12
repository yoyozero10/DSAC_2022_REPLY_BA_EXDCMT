/**
 * @author Branium Academy
 * @version 2021.10
 * @website https://braniumacademy.net/
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;
const int N = 9;

// khai báo hàm nguyên mẫu
bool isSafe(int board[N][N], int row, int col, int num);
bool solveSudoku(int board[N][N]);
void showResult(int board[N][N]);
void readPresetData(int board[N][N], ifstream& ifs);

int main() {
    int board[N][N] = { 0 };
    int testNumber = 1;
    int t;
    ifstream ifs("input4.txt");
    if (ifs) {
        ifs >> t;
        while (t-- > 0) {
            readPresetData(board, ifs);
            cout << "Test " << testNumber++ << ": \n";
            if (solveSudoku(board)) {
                showResult(board);
            }
            else {
                cout << "Khong co loi giai.\n";
            }
        }
        ifs.close();
    }
    else {
        cout << "Khong mo duoc file.\n";
    }
}

bool isSafe(int board[N][N], int row, int col, int num) {
    // kiểm tra xem trên hàng cần thêm số num đã tồn tại num chưa
    for (int c = 0; c < N; c++) {
        if (board[row][c] == num) { // nếu đã tồn tại
            return false; // trả về không đặt được num ở hàng này
        }
    }
    // kiểm tra trên cột hiện tại đã có giá trị num chưa
    for (int r = 0; r < N; r++) {
        if (board[r][col] == num) {
            return false; // không đặt được num vào ô này
        }
    }
    // kiểm tra cụm 9 ô bao quanh ô (row, col) xem đã tồn tại giá trị num chưa
    int boxSize = 3;
    int boxRowStart = row - row % boxSize;
    int boxColStart = col - col % boxSize;
    for (int i = boxRowStart; i < boxRowStart + boxSize; i++) {
        for (int j = boxColStart; j < boxColStart + boxSize; j++) {
            if (board[i][j] == num) { // nếu đã tồn tại ô chứa giá trị num
                return false; // không đặt được num vào ô này
            }
        }
    }
    // mặc định giá trị num chưa tồn tại trong phạm vi cần kiểm tra
    return true;
}

bool solveSudoku(int board[N][N]) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }
    if (isEmpty) {
        return true;
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            else { // nếu không dẫn tới lời giải
                board[row][col] = 0; // quay lui
            }
        }
    }
    return false;
}

void showResult(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void readPresetData(int board[N][N], ifstream& ifs) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ifs >> board[i][j];
        }
    }
}