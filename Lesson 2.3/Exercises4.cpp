#include <iostream>
#include <string>
using namespace std;
const int width = 13;
const int height = 9;

// hàm tạo hình dấu +
void make(string rect[height][width]) {
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++)
		{
			rect[i - 1][j - 1] = "   "; // giả định ban đầu mỗi phần tử là 3 dấu cách
			if ((j == 5 || j == 9) && i != 5) { // tất cả các phần tử trên cột 5, 9 trừ hàng 5
				rect[i - 1][j - 1] = " * ";
			}
			if ((j == 1 || j == 13) && i >= 4 && i <= 6) { // tất cả các phần tử trên cột 1, cột 13 từ hàng 4-6
				rect[i - 1][j - 1] = " * ";
			}
			if ((i == 1 || i == 9) && j >= 5 && j <= 9) { // tất cả các phần tử trên hàng 1, 9 và cột 5-9
				rect[i - 1][j - 1] = " * ";
			}
			if ((i == 4 || i == 6) && (j <= 5 || j >= 9)) { // tất cả các phần tử hàng 4, 6 cột 5-9
				rect[i - 1][j - 1] = " * "; // nhận dấu * kèm 2 dấu cách ở hai đầu cho dễ nhìn
			}
		}
	}
}

// hàm hiển thị dấu + lên màn hình
void drawPlusSign(string sign[height][width]) {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << sign[i][j];
		}
		cout << "\n\n";
	}
}

int main()
{
	string plusSign[height][width];
	make(plusSign);
	drawPlusSign(plusSign);
}