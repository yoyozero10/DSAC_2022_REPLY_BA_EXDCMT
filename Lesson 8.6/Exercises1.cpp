﻿/**
* @author Branium Academy
* @version 2022.05
* @ see https://braniumacademy.net
*/

#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Student {
private:
	string id;
	string first;
	string last;
	string mid;
	float gpa;
	friend ostream& operator << (ostream&, const Student&);
public:
	Student() {
		id = "";
		first = id;
		last = id;
		mid = id;
		gpa = 0;
	}

	Student(string id) {
		this->id = id;
	}

	Student(string id, string first, string last, string mid, float gpa) {
		this->id = id;
		this->first = first;
		this->last = last;
		this->mid = mid;
		this->gpa = gpa;
	}

	string getId() { return id; }
	string getFirst() { return first; }
	string getLast() { return last; }
	string getMid() { return mid; }
	float getGpa() { return gpa; }
	void setId(string id) { this->id = id; }
	void setFirst(string first) { this->first = first; }
	void setLast(string last) { this->last = last; }
	void setMid(string mid) { this->mid = mid; }
	void setGpa(float gpa) { this->gpa = gpa; }

	bool operator==(Student& other) {
		return id.compare(other.id) == 0;
	}
};

ostream& operator << (ostream& os, const Student& s) {
	os << "[" << s.id << ", " << s.last << ", " << s.mid 
		<< ", " << s.first << ", " << s.gpa << "]";
	return os;
}

// 1
template<class V> class Entry {
	friend ostream& operator << <>(ostream&, const Entry<V>&);
public:
	string key;
	V value;
	size_t hash;

	Entry(string key, V value = V()) {
		this->key = key;
		this->value = value;
		hash = hashCode();
	}

	size_t hashCode() {
		size_t result = 0;
		size_t n = key.length();
		for (size_t i = 1; i <= n; i++)
		{
			result += key[i - 1] * (size_t)pow(31, n - i);
		}
		return result;
	}
};

template<class V> ostream& operator << (ostream& os, const Entry<V>& entry) {
	os << "[" << entry.key << " - " << entry.value << "]";
	return os;
}

// 2
template<class V> class HashTable {
private:
	size_t capacity;
	list<Entry<V>>* table;
	const int MAX_SIZE = INT_MAX - 8;
	const float loadFactor = 0.75f;
	int modCount; // số lần sửa đổi cấu trúc bảng băm
	size_t threshold; // ngưỡng băm lại bảng
	size_t count; // số phần tử của bảng băm
public:
	HashTable(int capacity = 10) {
		if (capacity <= 0) {
			capacity = 10;
		}
		this->capacity = capacity;
		this->table = new list<Entry<V>>[capacity];
		modCount = 0;
		threshold = (size_t)(capacity * loadFactor);
	}

	size_t hashCode(size_t code) {
		return code % capacity;
	}

	// 8
	bool isEmpty() {
		return this->size() == 0;
	}

	// 9
	size_t size() {
		size_t counter = 0;
		for (size_t i = 0; i < capacity; i++) {
			for (auto it = table[i].begin(); it != table[i].end(); ++it) {
				if ((*it).key != "") {
					counter++;
				}
			}
		}
		return counter;
	}

	// 10
	void remove(string key) {
		Student s(key);
		Entry<V> entry(key, s);
		auto index = hashCode(entry.hash);
		if (index < capacity) { // nếu tồn tại chỉ số của key cho trước
			// tìm sv có mã key
			for (auto it = table[index].begin(); it != table[index].end(); ++it) {
				if ((*it).hash == entry.hash) {
					table[index].erase(it); // xóa bỏ entry với key cho trước
					return; // kết thúc
				}
			}
		}
	}

	// 3
	void addEntry(string key, V value) {
		Entry<V> entry(key, value);
		size_t index = hashCode(entry.hash);
		table[index].push_back(entry);
	}

	// 4
	V get(string key) {
		Student s(key);
		Entry<V> entry(key, s);
		auto index = hashCode(entry.hash);
		if (index < capacity) { // nếu tồn tại chỉ số của key cho trước
			// tìm sv có mã key
			for (auto it = table[index].begin(); it != table[index].end(); ++it) {
				if ((*it).key == key) {
					return (*it).value; // trả về sv đó
				}
			}
		}
		return s; // trả về sv rỗng
	}

	// 5
	bool contains(V value) {
		return containsValue(value);
	}

	// 6
	bool containsValue(V value) {
		for (size_t i = 0; i < capacity; i++) {
			for (auto iter = this->table[i].begin(); iter != this->table[i].end(); iter++) {
				return (*iter).value == value;
			}
		}
		return false;
	}

	// 7
	bool containsKey(string key) {
		Student s(key);
		Entry<V> entry(key, s);
		auto index = hashCode(entry.hash);
		return index < this->capacity;
	}

	void displayHashTable() {
		for (size_t i = 0; i < capacity; i++)
		{
			cout << i << ": ";
			for (auto x : table[i])
			{
				cout << " --> " << x;
			}
			cout << endl;
		}
	}

	// 11
	bool update(string key, V newValue) {
		Entry<V> entry(key);
		size_t index = hashCode(entry.hash);
		for (auto i = table[index].begin(); i != table[index].end(); i++)
		{
			if ((*i).hash == entry.hash) {
				(*i).value = newValue;
				return true;
			}
		}
		return false; // update failed
	}

	// 12
	void rehash() {
		int oldCapacity = capacity;
		list<Entry<V>>* oldMap = table;
		int newCapacity = (oldCapacity << 1) + 1;
		if (newCapacity - MAX_SIZE > 0) {
			if (oldCapacity >= MAX_SIZE) {
				return;
			}
			newCapacity = MAX_SIZE;
		}
		list<Entry<V>>* newMap = new list<Entry<V>>[newCapacity];
		modCount++;
		threshold = min((size_t)(newCapacity * loadFactor), MAX_SIZE + 1);
		table = newMap;
		capacity = newCapacity;
		// copy các phần tử từ bảng cũ sang bảng mới
		for (int i = 0; i < oldCapacity; i++)
		{
			for (auto x : oldMap[i])
			{
				size_t index = hashCode(x.hash);
				newMap[index].push_back(x);
			}
		}
	}

	size_t min(size_t first, size_t second) {
		return first < second ? second : first;
	}

	vector<string> keys() {
		vector<string> result;
		for (size_t i = 0; i < capacity; i++)
		{
			for (auto x : table[i]) {
				result.push_back(x.key);
			}
		}
		return result;
	}

	vector<V> values() {
		vector<V> result;
		for (size_t i = 0; i < capacity; i++)
		{
			for (auto x : table[i]) {
				result.push_back(x.value);
			}
		}
		return result;
	}

	vector<Entry<V>> entries() {
		vector<Entry<V>> result;
		for (size_t i = 0; i < capacity; i++)
		{
			for (auto x : table[i]) {
				result.push_back(x);
			}
		}
		return result;
	}

	~HashTable() {
		delete[] table;
	}
};

// hiển thị dữ liệu ra màn hình
template<class T> void printData(vector<T> data) {
	for (auto x : data)
	{
		cout << x << endl;
	}
}

int main() {
	HashTable<Student> ht(5);
	Student s1("B25DCCN100", "Hoang", "Nguyen", "Minh", 3.25f);
	Student s2("B25DCCN101", "Nhung", "Le", "Hong", 3.26f);
	Student s3("B25DCCN102", "Hoa", "Tran", "Thanh", 3.29f);
	Student s4("B25DCCN103", "Huong", "Mai", "Thu", 3.55f);
	Student s5("B25DCCN104", "Loan", "Ngo", "Thuy", 3.75f);
	// test chuc nang so 3
	ht.addEntry(s1.getId(), s1);
	ht.addEntry(s2.getId(), s2);
	ht.addEntry(s3.getId(), s3);
	ht.addEntry(s4.getId(), s4);
	ht.addEntry(s5.getId(), s5);

	// hiển thị thông tin bảng băm
	cout << "==> Thong tin bang bam truoc khi bam lai:\n";
	ht.displayHashTable();

	// thêm mới các sv
	Student s6("B25DCCN108", "Linh", "Khuc", "Thuy", 3.45f);
	Student s7("B25DCCN106", "Mai", "Le", "Thuy", 3.65f);
	Student s8("B25DCCN105", "Khanh", "Tran", "Quoc", 3.35f);
	ht.addEntry(s6.getId(), s6);
	ht.addEntry(s7.getId(), s7);
	ht.addEntry(s8.getId(), s8);

	// hiển thị thông tin bảng băm
	cout << "==> Thong tin bang bam sau khi bam lai:\n";
	ht.displayHashTable();

	cout << "================== Danh sach keys:==================\n";
	printData(ht.keys());
	cout << "================= Danh sach values:=================\n";
	printData(ht.values());
	cout << "============= Danh sach cap key-value:==============\n";
	printData(ht.entries());

	return 0;
}