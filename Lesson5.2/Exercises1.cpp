/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

template<class T> class Queue {
	T* data;
	int capacity;
	int currentSize;
public:
	Queue(int cap = 10) {
		if (cap <= 0) {
			capacity = 10;
		}
		else {
			capacity = cap;
		}
		data = new T[capacity];
		currentSize = 0;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	bool isFull() {
		return currentSize == capacity;
	}

	T front() {
		if (!isEmpty()) {
			return data[0];
		}
		else {
			throw exception("Queue rong.");
		}
	}

	T back() {
		if (!isEmpty()) {
			return data[currentSize - 1];
		}
		else {
			throw exception("Queue rong.");
		}
	}

	void push(T value) {
		if (!isFull()) {
			data[currentSize++] = value;
		}
		else {
			cout << "Queue day, khong the push.\n";
		}
	}

	T pop() {
		if (!isEmpty()) {
			T value = data[0];
			currentSize--;
			for (int i = 0; i < currentSize; i++)
			{
				data[i] = data[i + 1];
			}
			return value;
		}
		else {
			throw exception("Queue rong.");
		}
	}

	int size() {
		return currentSize;
	}

	void sort() {
		std::sort(data, data + currentSize, greater<T>());
	}

	~Queue() {
		delete[] data;
	}
};

int main()
{
	int n;
	cin >> n;
	int max = n;
	Queue<int>* queue = new Queue<int>(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		queue->push(x);
		queue->sort();
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