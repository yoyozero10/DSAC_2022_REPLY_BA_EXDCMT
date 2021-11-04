/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
#include <exception>
using namespace std;

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
		currentSize = 0;
		data = new T[capacity];
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
		if (data[index] < data[parentIndex]) {
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
	T const front() {
		if (currentSize >= 0) {
			return data[0];
		}
		else {
			return T();
		}
	}

	T pop() {
		if (currentSize > 0) {
			T removed = data[0];
			data[0] = data[currentSize - 1];
			currentSize--;
			siftDown(0);
			return removed;
		}
		else {
			throw exception("Hang doi rong.");
		}
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

	int size() {
		return currentSize;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	~PriorityQueue() {
		delete[] data;
	}
};

// quy ước giá trị nhỏ hơn sẽ có mức ưu tiên cao hơn
int main() {
	PriorityQueue<string> heap;
	int choice;
	do
	{
		cout << "================ OPTIONS ================\n";
		cout << "1. Them moi mot node.\n";
		cout << "2. Lay node dau tien trong queue.\n";
		cout << "3. Xoa node dau khoi queue.\n";
		cout << "4. Hien thi cac phan tu trong queue.\n";
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
			cout << "Nhap x = ";
			cin >> x;
			heap.push(x);
			break;
		}
		case 2:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				cout << "Gia tri node dau tien trong queue: " << heap.front() << endl;
			}
			break;
		case 3:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				cout << "Node vua xoa khoi queue: " << heap.pop() << endl;
			}
			break;
		case 4:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				cout << "Cac phan tu trong heap: \n";
				heap.showElements();
			}
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