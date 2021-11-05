/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// max heap template
template<class T> class PriorityQueue {
	T* data;
	int currentSize;
	int capacity;
public:
	PriorityQueue(int cap = 10) {
		if (cap <= 0) {
			capacity = 10;
		}
		else {
			capacity = cap;
		}
		data = new T[capacity];
		currentSize = 0;
	}

	bool push(T value) {
		if (currentSize < capacity) {
			data[currentSize] = value;
			siftUp(currentSize);
			currentSize++;
			return true;
		}
		else {
			return false;
		}
	}

	void siftUp(int index) {
		int parentIndex = (index - 1) / 2;
		if (data[index] > data[parentIndex]) {
			swap(data[index], data[parentIndex]);
			siftUp(parentIndex);
		}
	}

	void showElements() {
		if (isEmpty()) {
			cout << "Queue rong.\n";
		}
		else {
			for (int i = 0; i < currentSize; i++)
			{
				cout << data[i] << " ";
			}
			cout << endl;
		}
	}

	int size() {
		return currentSize;
	}
	// hàm kiểm tra rỗng
	bool isEmpty() {
		return currentSize == 0;
	}
	// hàm kiểm tra đầy
	bool isFull() {
		return currentSize == capacity;
	}
	// hàm xóa node khỏi Queue
	bool pop() {
		if (!isEmpty()) {
			data[0] = data[currentSize - 1];
			currentSize--;
			siftDown(0);
			return true;
		}
		else {
			return false;
		}
	}
	// hàm tìm node
	int findNodeIndex(T value) {
		for (int i = 0; i < currentSize; i++)
		{
			if (data[i] == value) {
				return i;
			}
		}
		return -1;
	}
	// hàm sàng xuống
	void siftDown(int index) {
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left < currentSize && data[left] > data[largest]) {
			largest = left;
		}
		if (right < currentSize && data[right] > data[largest]) {
			largest = right;
		}
		if (largest != index) {
			swap(data[index], data[largest]);
			siftDown(largest);
		}
	}
	// hàm trả về phần tử lớn nhất trong Queue
	T front() {
		if (currentSize > 0) {
			return data[0];
		}
		else {
			return T();
		}
	}

	// hàm hủy
	~PriorityQueue() {
		delete[] data;
	}
};

int main() {
	PriorityQueue<string> queue;
	int choice;
	do
	{
		cout << "================ OPTIONS ================\n";
		cout << "1. Them moi mot node vao queue.\n";
		cout << "2. Hien thi cac node trong queue.\n";
		cout << "3. Tim node x trong queue.\n";
		cout << "4. Lay phan tu dau hang doi.\n";
		cout << "5. Xoa phan tu dau hang doi.\n";
		cout << "6. Kiem tra hang doi rong.\n";
		cout << "7. Kiem tra hang doi day.\n";
		cout << "8. Cho biet kich thuoc cua hang doi.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== The End ==>\n";
			break;
		case 1:
		{
			string x;
			cout << "Nhap vao mot tu: ";
			cin >> x;
			queue.push(x);
			break;
		}
		case 2:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				cout << "==== Cac tu co trong queue ====\n";
				queue.showElements();
			}
			break;
		case 3:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				string x;
				cout << "Nhap tu can tim: ";
				cin >> x;
				if (queue.findNodeIndex(x) >= 0) {
					cout << "\"" << x << "\" ton tai trong queue.\n";
				}
				else {
					cout << "\"" << x << "\" khong ton tai trong queue.\n";
				}
			}
			break;
		case 4:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				cout << "Gia tri dau hang doi: " << queue.front() << endl;
			}
			break;
		case 5:
			if (queue.isEmpty()) {
				cout << "Queue rong.\n";
			}
			else {
				if (queue.pop()) {
					cout << "Xoa thanh cong.\n";
				}
				else {
					cout << "Xoa that bai.\n";
				}
			}
			break;
		case 6:
			if (!queue.isEmpty()) {
				cout << "Queue khong rong.\n" << endl;
			}
			else {
				cout << "Queue rong.\n";
			}
			break;
		case 7:
			if (queue.isFull()) {
				cout << "Hang doi day.\n";
			}
			else {
				cout << "Hang doi chua day.\n";
			}
			break;
		case 8:
			cout << "So phan tu hien co trong queue: " << queue.size() << endl;
			break;
		default:
			cout << "<=== Sai lua chon. Vui long chon lai! ===>\n";
			break;
		}
	} while (choice != 0);
	return 0;
}