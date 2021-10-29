/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

template<class T> class CircularQueue {
	int headIndex;
	int tailIndex;
	int capacity;
	int currentElement;
	T* data;
public:
	CircularQueue(int cap = 10) {
		if (cap <= 0) {
			capacity = 10;
		}
		else {
			capacity = cap;
		}
		data = new T[capacity];
		currentElement = 0;
		headIndex = -1;
		tailIndex = -1;
	}

	bool isEmpty() {
		return currentElement == 0;
	}

	bool isFull() {
		return currentElement == capacity;
	}

	int size() {
		return currentElement;
	}

	bool push(T e) {
		if (isFull()) {
			cout << "Queu day. Them that bai.\n";
			return false;
		}
		if (isEmpty()) {
			headIndex = 0;
		}
		tailIndex = (tailIndex + 1) % capacity;
		data[tailIndex] = e;
		currentElement++;
		return true;
	}

	T* pop() {
		if (isEmpty()) {
			return nullptr;
		}
		else {
			int indexToRemove = headIndex;
			currentElement--;
			if (headIndex == tailIndex) {
				headIndex = tailIndex = -1;
			}
			else {
				headIndex = (headIndex + 1) % capacity;
			}
			return &data[indexToRemove];
		}
	}

	T* front() {
		if (isEmpty()) {
			return nullptr;
		}
		else {
			return &data[headIndex];
		}
	}

	T* back() {
		if (isEmpty()) {
			return nullptr;
		}
		else {
			return &data[tailIndex];
		}
	}

	void showNodes() {
		if (isEmpty()) {
			cout << "Queue rong." << endl;
		}
		else {
			cout << "Cac phan tu trong queue: ";
			for (int i = headIndex; i != tailIndex; i++)
			{
				cout << data[i] << " ";
			}
			cout << data[tailIndex] << endl;
		}
	}

	~CircularQueue() {
		delete[] data;
	}
};


int main()
{
	CircularQueue<long> queue(100);
	int choice;
	do
	{
		cout << "<=================== OPTIONS ===================>\n";
		cout << "1. Them moi phan tu vao hang doi.\n";
		cout << "2. Xoa va tra ve phan tu dau hang doi.\n";
		cout << "3. Lay phan tu dau hang doi.\n";
		cout << "4. Lay so phan tu hien co trong hang doi.\n";
		cout << "5. Hien thi cac phan tu trong hang doi.\n";
		cout << "6. Kiem tra hang doi co rong khong.\n";
		cout << "7. Kiem tra hang doi day chua.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban? ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== Cam on ban da su dung dich vu ==>\n";
			break;
		case 1:
		{
			int x;
			cout << "Nhap gia tri cua phan tu moi: ";
			cin >> x;
			queue.push(x);
			break;
		}
		case 2:
			if (!queue.isEmpty()) {
				cout << "Phan tu bi xoa khoi queue: " << *(queue.pop()) << endl;
			}
			else {
				cout << "Hang doi rong.\n";
			}
			break;
		case 3:
			if (!queue.isEmpty()) {
				cout << "Phan tu dau hang doi: " << *(queue.front()) << endl;
			}
			else {
				cout << "Hang doi rong.\n";
			}
			break;
		case 4:
			cout << "So phan tu hien co trong hang doi: " << queue.size() << endl;
			break;
		case 5:
			if (!queue.isEmpty()) {
				while (!queue.isEmpty()) {
					cout << *(queue.pop()) << "->";
				}
				cout << "null\n";
			}
			else {
				cout << "Hang doi rong.\n";
			}
			break;
		case 6:
			cout << boolalpha << "Hang doi rong? " << queue.isEmpty() << endl;
			break;
		case 7:
			cout << boolalpha << "Hang doi day? " << queue.isFull() << endl;
			break;
		default:
			cout << "Sai chuc nang. Vui long chon lai!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}