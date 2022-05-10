/**
 * @author Branium Academy
 * @version 2021.10
 * @website https://braniumacademy.net/
 */
#include <iostream>
#include <iomanip>
using namespace std;
const int N = 8;

void showResult(int sol[N][N]);
bool solveKnightTour(int x, int y, int moveStep, int sol[N][N], int xMove[N], int yMove[N]);
bool isSafe(int x, int y, int sol[N][N]);

int main() {
    int sol[N][N]; // mảng lưu các vi trí trên bàn cờ
        // khởi tạo giá trị mặc định cho mảng
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = -1;
        }
    }
    // các cặp tọa độ mà quân mã có thể di chuyển từ vị trí hiện tại.
    int xMove[] = {2, 1, -1, 2, -2, 1, -1, -2};
    int yMove[] = {1, -2, 2, -1, -1, 2, -2, 1};
    // giả sử quân mã bắt đầu từ ô đầu tiên tọa độ (0, 0)
    sol[0][0] = 0;
    // tìm lời giải:
    bool isSolved = solveKnightTour(0, 0, 1, sol, xMove, yMove);
    if (!isSolved) {
        cout << "Khong tim duoc loi giai.\n";
    }
    else {
        showResult(sol);
    }
}

/**
     * Phương thức tìm lời giải cho bài toán. Tại vị trí (x, y) nếu đặt quân mã dẫn tới lời giải sẽ đánh dấu
     * vị trí đó với giá trị g là bước đi kế tiếp để tiến đến kết quả cuối cùng. Sau khi thực hiện mọi bước
     * đi của quân mã sẽ được ghi lại trong ma trận chứa lời giải sau cùng.
     *
     * @param x        tọa độ x của ô đang xem xét đặt quân mã
     * @param y        tọa độ y của ô đang xem xét đặt quân mã
     * @param moveStep bước đi tiếp theo của quân mã
     * @param sol      ma trận kết quả
     * @param xMove    các tọa độ x mà quân mã có thể di chuyển tới từ vị trí hiện thời
     * @param yMove    các tọa độ y mà quân mã có thể di chuyển tới từ vị trí hiện thời
     * @return true nếu tìm được 1 lời giải và false nếu không tìm được lời giải
     */
bool solveKnightTour(int x, int y, int moveStep, int sol[N][N], int xMove[N], int yMove[N]) {
    int nextX;
    int nextY;
    if (moveStep == N * N) {
        return true;
    }
    for (int i = 0; i < N; i++) {
        nextX = x + xMove[i];
        nextY = y + yMove[i];
        if (isSafe(nextX, nextY, sol)) {
            sol[nextX][nextY] = moveStep;
            if (solveKnightTour(nextX, nextY, moveStep + 1, sol, xMove, yMove)) {
                return true;
            }
            else {
                sol[nextX][nextY] = -1; // quay lui
            }
        }
    }
    return false;
}

/**
 * Phương thức kiểm tra việc đặt quân mã ở vị trí x, y có thỏa mãn hay không
 *
 * @param x   tọa độ vị trí x tại đó cần đặt quân mã
 * @param y   tọa độ vị trí y tại đó cần đặt quân mã
 * @param sol ma trận l?u kết quả
 * @return true nếu quân mã có thể đặt được tại vị trí (x, y) trong ma trận sol
 */
bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N&& y >= 0 && y < N&& sol[x][y] == -1);
}

/**
 * Phương thức hiển thị kết quả
 *
 * @param sol ma trận kết quả
 */
void showResult(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << sol[i][j];
        }
        cout << endl;
    }
}