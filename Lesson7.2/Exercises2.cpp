/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
using namespace std;

// sau đây là một max heap chỉ có thể lưu trữ được các số nguyên tới kiểu int:
class Heap {
	int* data;
	int currentSize;
	int capacity;
public:
	Heap(int cap = 10) {
		if (cap <= 0) {
			capacity = 10;
		}
		else {
			capacity = cap;
		}
		currentSize = 0;
		data = new int[capacity];
	}

	bool add(int value) {
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
			cout << "Heap rong.\n";
		}
		else {
			for (int i = 0; i < currentSize; i++)
			{
				cout << data[i] << ' ';
			}
			cout << endl;
		}
	}

	// phần tử có giá trị lớn nhất trong heap
	int const front() {
		return data[0];
	}

	int size() {
		return currentSize;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	~Heap() {
		delete[] data;
	}
};

int main() {
	Heap heap;
	int choice;
	do
	{
		cout << "================ OPTIONS ================\n";
		cout << "1. Them moi mot node.\n";
		cout << "2. Hien thi cac phan tu trong heap.\n";
		cout << "3. Cho biet phan tu lon nhat trong heap.\n";
		cout << "4. Lay kich thuoc hien tai cua heap.\n";
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
			int x;
			cout << "Nhap x = ";
			cin >> x;
			heap.add(x);
			break;
		}
		case 2:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				cout << "Cac phan tu trong heap: \n";
				heap.showElements();
			}
			break;
		case 3:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				cout << "Phan tu lon nhat trong heap: " << heap.front() << endl;
			}
			break;
		case 4:
			cout << "Kich thuoc hien thoi cua heap: " << heap.size() << endl;
			break;
		default:
			cout << "Sai lua chon. Vui long thu lai.\n";
			break;
		}
	} while (choice != 0);

	return 0;
}
// ví dụ một max heap:
//             90
//           /    \
//		   70     80
//        / \    /  \
//       40 30  10  50
//      / \
//     15  20