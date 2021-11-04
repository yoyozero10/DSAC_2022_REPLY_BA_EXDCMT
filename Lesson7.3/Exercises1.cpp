/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.11
 *
 */
#include <iostream>
using namespace std;

template<class T> class Heap {
	T* data;
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
		data = new T[capacity];
		currentSize = 0;
	}

	bool add(T value) {
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

	int size() {
		return currentSize;
	}

	bool isEmpty() {
		return currentSize == 0;
	}
	// hàm xóa node khỏi heap
	bool remove(T value) {
		int index = findNodeIndex(value);
		if (index >= 0) {
			data[index] = data[currentSize - 1];
			currentSize--;
			siftDown(index);
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
		return false;
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
	// hàm trả về phần tử lớn nhất trong heap
	T front() {
		if (currentSize > 0) {
			return data[0];
		}
		else {
			return T();
		}
	}
	// hàm hủy
	~Heap() {
		delete[] data;
	}
};

int main() {
	Heap<int> heap;
	int choice;
	do
	{
		cout << "================ OPTIONS ================\n";
		cout << "1. Them moi mot node.\n";
		cout << "2. Hien thi cac phan tu trong heap.\n";
		cout << "3. Tim gia tri x trong heap.\n";
		cout << "4. Xoa node co gia tri x.\n";
		cout << "5. Cho biet phan tu lon nhat trong heap.\n";
		cout << "6. Cho biet kich thuoc cua heap.\n";
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
				int x;
				cout << "Nhap gia tri can tim x = ";
				cin >> x;
				if (heap.findNodeIndex(x) >= 0) {
					cout << "Gia tri " << x << " ton tai trong heap.\n";
				}
				else {
					cout << x << " khong ton tai trong heap.\n";
				}
			}
			break;
		case 4:
			if (heap.isEmpty()) {
				cout << "Heap rong.\n";
			}
			else {
				int x;
				cout << "Nhap gia tri can xoa x = ";
				cin >> x;
				if (heap.remove(x)) {
					cout << "Xoa thanh cong.\n";
				}
				else {
					cout << "Xoa that bai.\n";
				}
			}
			break;
		case 5:
			cout << "Phan tu lon nhat trong heap: " << heap.front() << endl;
			break;
		case 6:
			cout << "Kich thuoc heap: " << heap.size() << endl;
			break;
		default:
			cout << "Sai lua chon. Vui long thu lai.\n";
			break;
		}
	} while (choice != 0);
	return 0;
}

//             90
//           /    \
//		   70     80
//        / \    /  \
//       40 30  10  50
//      / \
//     15  20