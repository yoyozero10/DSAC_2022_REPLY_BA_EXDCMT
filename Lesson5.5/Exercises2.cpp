/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <exception>
using namespace std;


// quy ước phần tử có giá trị lớn hơn thì mức ưu tiên cao hơn
class PriorityQueue {
private:
	long* data;
	int currentSize;
	int capacity;
public:
	PriorityQueue(int cap = 10) {
		currentSize = 0;
		capacity = cap;
		data = new long[capacity];
	}
	// kiểm tra hàng đợi rỗng
	bool isEmpty() {
		return currentSize == 0;
	}
	// kiểm tra hàng đợi đầy
	bool isFull() {
		return currentSize == capacity;
	}
	// thêm phần tử vào cuối hàng đợi
	bool push(long value) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			data[currentSize++] = value;
		}
		else if (value < data[currentSize - 1]) {
			data[currentSize++] = value;
		}
		else {
			int rightPosition = 0;
			// tìm vị trí chính xác của value
			for (int i = 0; i < currentSize; i++)
			{
				if (data[i] <= value) {
					rightPosition = i;
					break;
				}
			}
			for (int i = currentSize; i > rightPosition; i--) {
				data[i] = data[i - 1];
			}
			data[rightPosition] = value;
			currentSize++;
		}
		return true;
	}
	// lấy phần tử đầu hàng đợi
	long front() {
		if (isEmpty()) {
			throw exception("Queue rong.");
		}
		else {
			return data[0];
		}
	}
	// lấy phần tử cuối hàng đợi
	long back() {
		if (isEmpty()) {
			throw exception("Queue rong.");
		}
		else {
			return data[currentSize - 1];
		}
	}
	// xóa và trả về phần tử đầu hàng đợi
	long pop() {
		if (isEmpty()) {
			throw exception("Queue rong.");
		}
		else {
			long frontValue = data[0];
			for (int i = 0; i < currentSize - 1; i++)
			{
				data[i] = data[i + 1];
			}
			currentSize--;
			return frontValue;
		}
	}
	// trả về số phần tử hiện thời trong hàng đợi
	int size() {
		return currentSize;
	}
	// liệt kê các phần tử có mức ưu tiên nhỏ nhất
	void minPriorityElements() {
		if (isEmpty()) {
			cout << "Queue rong.\n";
		}
		else {
			cout << "Vi tri phan tu dau tien co muc uu tien nho nhat: ";
			long minPriorityValue = data[currentSize - 1];
			for (int i = 0; i < currentSize; i++)
			{
				if (data[i] == minPriorityValue) {
					cout << i << endl;
					break;
				}
			}
		}
	}
	// hiển thị các phần tử cùng với mức ưu tiên của nó
	void printElements() {
		for (int i = 0; i < currentSize; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	// hàm hủy
	~PriorityQueue() {
		delete[] data;
	}
};

int main() {
	// khai báo queue có tối đa 100 phần tử
	PriorityQueue queue(100);
	int choice;
	do
	{
		cout << "<=============== MENU ===============>\n";
		cout << "1. Them moi phan tu vao hang doi.\n";
		cout << "2. Xoa va tra ve phan tu dau hang doi.\n";
		cout << "3. Lay phan tu dau hang doi.\n";
		cout << "4. Lay phan tu cuoi hang doi.\n";
		cout << "5. Lay so phan tu hien co trong hang doi.\n";
		cout << "6. Hien thi cac phan tu cua hang doi.\n";
		cout << "7. Kiem tra queue rong khong.\n";
		cout << "8. Kiem tra queue day chua.\n";
		cout << "9. Tim chi so phan tu dau tien co muc uu tien nho nhat.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== Xin chao va cam on quy vi da su dung dich vu ==>\n";
			break;
		case 1:
		{
			int x;
			cout << "Nhap gia tri can them moi: ";
			cin >> x;
			queue.push(x);
			break;
		}
		case 2: 
		{
			try {
				cout << "Phan tu vua xoa: " << queue.pop() << endl;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 3:
		{
			try {
				cout << "Phan tu dau hang doi: " << queue.front() << endl;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 4:
		{
			try {
				cout << "Phan tu cuoi hang doi: " << queue.back() << endl;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 5:
			cout << "So phan tu hien co trong hang doi: " << queue.size() << endl;
			break;
		case 6:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				cout << "Cac phan tu trong hang doi: \n";
				queue.printElements();
			}
			break;
		case 7:
			cout << "Queue rong? " << boolalpha << queue.isEmpty() << endl;
			break;
		case 8:
			cout << "Queue day? " << boolalpha << queue.isFull() << endl;
			break;
		case 9:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				queue.minPriorityElements();
			}
			break;
		default:
			cout << "Sai chuc nang. Vui long chon lai.\n";
			break;
		}
	} while (choice != 0);
	return 0;
}