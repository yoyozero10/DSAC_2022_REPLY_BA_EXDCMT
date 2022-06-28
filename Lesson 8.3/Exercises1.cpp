/**
* @author Branium Academy
* @version 2022.05
* @ see https://braniumacademy.net
*/

#include <iostream>
#include <list>
#include <string>
#include <cmath>
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
public:
	HashTable(int capacity = 10) {
		if (capacity < 0) {
			capacity = 10;
		}
		this->capacity = capacity;
		this->table = new list<Entry<V>>[capacity];
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
				if ((*it).key == key) {
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

	~HashTable() {
		delete[] table;
	}
};

int main() {
	HashTable<Student> ht;
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
	cout << "==> Thong tin bang bam truoc khi xoa:\n";
	ht.displayHashTable();

	// 4
	cout << ht.get("B25DCCN101") << endl;
	// 5 + 6
	cout << "Chua sv ma B25DCCN101? " << ht.contains(s1) << endl;
	// 7
	cout << "Chua key B25DCCN103? " << ht.containsKey("B25DCCN103") << endl;
	// 8
	cout << "Bang bam rong? " << ht.isEmpty() << endl;
	// 9
	cout << "Kich thuoc bang bam: " << ht.size() << endl;
	//10
	ht.remove(s5.getId());

	// hiển thị thông tin bảng băm
	cout << "==> Thong tin bang bam sau khi xoa sv 'B25DCCN104':\n";
	ht.displayHashTable();

	return 0;
}