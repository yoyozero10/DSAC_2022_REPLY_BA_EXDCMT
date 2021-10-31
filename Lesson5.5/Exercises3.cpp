/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
using namespace std;

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
		return data[0];
	}
	// lấy phần tử cuối hàng đợi
	long back() {
		return data[currentSize - 1];
	}
	// xóa và trả về phần tử đầu hàng đợi
	void pop() {
		for (int i = 0; i < currentSize - 1; i++)
		{
			data[i] = data[i + 1];
		}
		currentSize--;
	}
	// trả về số phần tử hiện thời trong hàng đợi
	int size() {
		return currentSize;
	}
	// hàm hủy
	~PriorityQueue() {
		delete[] data;
	}
};

int main()
{
	int n;
	cin >> n;
	int max = n;
	PriorityQueue* queue = new PriorityQueue(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		queue->push(x);
		while (!queue->isEmpty() && queue->front() == max) {
			cout << queue->front() << ' ';
			queue->pop();
			--max;
		}
		cout << endl;
	}
	delete queue;
	return 0;
}