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
    int sol[N][N]; // m?ng l?u các v? trí trên bàn c?
        // kh?i t?o giá tr? m?c ??nh cho m?ng
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = -1;
        }
    }
    // các c?p t?a ?? mà quân mã có th? di chuy?n t? v? trí hi?n t?i.
    int xMove[] = {2, 1, -1, 2, -2, 1, -1, -2};
    int yMove[] = {1, -2, 2, -1, -1, 2, -2, 1};
    // gi? s? quân mã b?t ??u t? ô ??u tiên t?a ?? (0, 0)
    sol[0][0] = 0;
    // tìm l?i gi?i:
    bool isSolved = solveKnightTour(0, 0, 1, sol, xMove, yMove);
    if (!isSolved) {
        cout << "Khong tim duoc loi giai.\n";
    }
    else {
        showResult(sol);
    }
}

/**
     * Ph??ng th?c tìm l?i gi?i cho bài toán. T?i v? trí (x, y) n?u ??t quân mã d?n t?i l?i gi?i s? ?ánh d?u
     * v? trí ?ó v?i giá tr? g là b??c ?i k? ti?p ?? ti?n ??n k?t qu? cu?i cùng. Sau khi th?c hi?n m?i b??c
     * ?i c?a quân mã s? ???c ghi l?i trong ma tr?n ch?a l?i gi?i sau cùng.
     *
     * @param x        t?a ?? x c?a ô ?ang xem xét ??t quân mã
     * @param y        t?a ?? y c?a ô ?ang xem xét ??t quân mã
     * @param moveStep b??c ?i ti?p theo c?a quân mã
     * @param sol      ma tr?n k?t qu?
     * @param xMove    các t?a ?? x mà quân mã có th? di chuy?n t?i t? v? trí hi?n th?i
     * @param yMove    các t?a ?? y mà quân mã có th? di chuy?n t?i t? v? trí hi?n th?i
     * @return true n?u tìm ???c 1 l?i gi?i và false n?u không tìm ???c l?i gi?i
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
 * Ph??ng th?c ki?m tra vi?c ??t quân mã ? v? trí x, y có th?a mãn hay không
 *
 * @param x   t?a ?? v? trí x t?i ?ó c?n ??t quân mã
 * @param y   t?a ?? v? trí y t?i ?ó c?n ??t quân mã
 * @param sol ma tr?n l?u k?t qu?
 * @return true n?u quân mã có th? ??t ???c t?i v? trí (x, y) trong ma tr?n sol
 */
bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N&& y >= 0 && y < N&& sol[x][y] == -1);
}

/**
 * Ph??ng th?c hi?n th? k?t qu?
 *
 * @param sol ma tr?n k?t qu?
 */
void showResult(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << sol[i][j];
        }
        cout << endl;
    }
}