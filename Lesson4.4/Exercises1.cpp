/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;

class Student {
	friend ostream& operator << (ostream&, const Student&);
	friend istream& operator >> (istream&, Student&);
	string id;
	string firstName;
	string lastName;
	string midName;
	int age;
	float gpa;
public:
	Student(string id = "", string first = "", 
		string last = "", string mid = "", int age = 0, float gpa = 0) {
		this->id = id;
		this->firstName = first;
		this->lastName = last;
		this->midName = mid;
		this->age = age;
		this->gpa = gpa;
	}

	void setId(string id) {
		this->id = id;
	}

	void setFirstName(string first) {
		this->firstName = first;
	}

	void setLastName(string last) {
		this->lastName = last;
	}

	void setMidName(string mid) {
		this->midName = mid;
	}

	void setAge(int age) {
		this->age = age;
	}

	void setGpa(float gpa) {
		this->gpa = gpa;
	}

	bool operator == (const Student& other) {
		return id.compare(other.id) == 0;
	}

	string getId() {
		return id;
	}

	string getFirstName() {
		return firstName;
	}

	string getLastName() {
		return lastName;
	}

	string getMidName() {
		return midName;
	}

	int getAge() {
		return age;
	}

	float getAvg() {
		return gpa;
	}

	string getFullName() const {
		return lastName + " " + midName + " " + firstName;
	}
};

istream& operator >> (istream& is, Student& s) {
	cout << "Ma sv: ";
	is >> s.id;
	cout << "Ho: ";
	is >> s.lastName;
	cout << "Dem: ";
	is.ignore();
	getline(is, s.midName);
	cout << "Ten: ";
	is >> s.firstName;
	cout << "Tuoi: ";
	is >> s.age;
	cout << "Diem tb: ";
	is >> s.gpa;
	return is;
}

ostream& operator << (ostream& os, const Student& s) {
	os << left << setw(10) << s.id << setw(25) << s.getFullName() 
	   << setw(10) << s.age << setw(10) << s.gpa << endl;
	return os;
}

int main() {
	stack<Student> students;
	int choice;
	do {
		cout << "<================= OPTIONS =================>\n";
		cout << "1. Them moi sinh vien vao stack.\n";
		cout << "2. Hien thi thong tin sv dau stack.\n";
		cout << "3. Cho biet so sinh vien hien co trong stack.\n";
		cout << "4. Hien thi danh sach sinh vien ra man hinh.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "Xin moi chon: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "<== Thank you and goodbye ==>\n";
			break;
		case 1:
		{
			Student s;
			cin >> s;
			students.push(s);
			break;
		}
		case 2:
			if (!students.empty()) {
				cout << students.top();
			}
			else {
				cout << "Danh sach sv rong.\n";
			}
			break;
		case 3:
			cout << "So sv hien co trong stack: " << students.size() << endl;
			break;
		case 4: 
			if (students.empty()) {
				cout << "Danh sach sv rong.\n";
			}
			else {
				cout << "<== Cac sv trong stack ==>\n";
				while (!students.empty()) {
					cout << students.top();
					students.pop();
				}
			}
			break;
		default:
			cout << "Wrong option. Please try again.\n";
			break;
		}
	} while (choice != 0);
}