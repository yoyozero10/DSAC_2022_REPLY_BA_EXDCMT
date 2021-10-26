/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class BankAccount {
	friend ostream& operator << (ostream&, const BankAccount&);
	string accNum; // số tài khoản
	string bankName; // ngân hàng phát hành
	long ballance; // số dư
	string owner; // chủ thẻ
	string startDate; // ngày phát hành
public:
	BankAccount(string accNum = "",
		string owner = "", string bankName = "", long ballance = 0, 
		string start = "01/01/2020") {
		this->accNum = accNum;
		this->owner = owner;
		this->ballance = ballance;
		this->bankName = bankName;
		this->startDate = start;
	}

	void setAccNum(string accNum) {
		this->accNum = accNum;
	}

	void setOwner(string owner) {
		this->owner = owner;
	}

	void setBankName(string bank) {
		this->bankName = bank;
	}

	void setBallance(long ballance) {
		this->ballance = ballance;
	}

	string getAccNum() {
		return accNum;
	}

	string getOwner() {
		return owner;
	}

	long getBallance() {
		return ballance;
	}

	string getBankName() {
		return bankName;
	}

	string getStartDate() {
		return startDate;
	}

	void setStartDate(string start) {
		startDate = start;
	}
};

ostream& operator << (ostream& os, const BankAccount& acc) {
	os << left << setw(16) << acc.accNum << setw(22) << acc.owner 
		<< setw(10) << acc.bankName << setw(12) << acc.ballance
		<< setw(12) << acc.startDate << endl;
	return os;
}

class Node { // sử dụng lớp template
public:
	BankAccount data; // dữ liệu của node hiện tại
	Node* next; // con trỏ trỏ tới node kế tiếp
	Node* prev; // con trỏ trỏ tới node liền trước

	Node(BankAccount data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
		this->prev = nullptr;
		this->data = data; // gán giá trị của data cho node
	}
};

class LinkedList {
private:
	Node* head; // con trỏ trỏ đến node đầu tiên trong danh sách
	Node* tail; // con trỏ trỏ tới node cuối của danh sách
public:
	// hàm khởi tạo
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	// chèn vào đầu danh sách liên kết
	void add(BankAccount data) {
		Node* p = new Node(data); // tạo node mới p
		if (isEmpty()) { // kiểm tra xem danh sách rỗng không
			head = tail = p; // gán giá trị cho head, tail
		}
		else { // nếu danh sách không rỗng
			p->next = head; // cập nhật node next của p
			head->prev = p; // cập nhật prev của node head cũ
			head = p; // cập nhật lại node head mới
		}
	}
	// chèn vào cuối danh sách liên kết
	void addTail(BankAccount data) { // chèn node vào cuối danh sách liên kết
		Node* p = new Node(data); // tạo node mới p
		if (!isEmpty()) {
			tail->next = p; // cập nhật node next của tail
			p->prev = tail; // cập nhật node prev của p
			tail = p; // cập nhật lại tail
		}
		else {
			head = tail = p; // gán head, tail cùng bằng p
		}
	}

	// hiển thị danh sách liên kết
	void showList() { // hàm hiển thị danh sách liên kết
		Node* p = head; // khởi đầu từ node head
		while (p != nullptr) // lặp chừng nào p chưa null
		{
			cout << p->data; // hiển thị data của p
			p = p->next; // cập nhật p
		}
	}

	// kiểm tra danh sách rỗng
	bool isEmpty() {
		return head == nullptr;
	}

	int namePosition(string fullName) {
		for (int i = fullName.size() - 1; i >= 0; i--) {
			if (fullName.at(i) == ' ') {
				return i + 1;
			}
		}
		return -1;
	}

	// hàm tìm hiển thị thông tin theo số tài khoản
	void findByAccNumber(string accNum) {
		bool existed = false;
		for (auto p = head; p != nullptr; p = p->next)
		{
			if (p->data.getAccNum().compare(accNum) == 0) {
				cout << p->data;
				existed = true;
			}
		}
		if (!existed) {
			cout << "<== Khong tim thay ket qua ==>\n";
		}
	}

	// hàm hiển thị các tài khoản phát hành vào ngày cho trước
	void findByReleaseDate(string date) {
		bool existed = false;
		for (auto p = head; p != nullptr; p = p->next)
		{
			if (p->data.getStartDate().compare(date) == 0) {
				cout << p->data;
				existed = true;
			}
		}
		if (!existed) {
			cout << "<== Khong tim thay ket qua ==>\n";
		}
	}

	int getYear(string dateStr) {
		return stoi(dateStr.substr(6));
	}

	int getMonth(string dateStr) {
		return stoi(dateStr.substr(3, 5));
	}

	int getDay(string dateStr) {
		return stoi(dateStr.substr(0, 2));
	}

	// hàm tìm kiếm theo số dư tk
	void findByBallance(long ballance) {
		bool existed = false;
		for (auto p = head; p != nullptr; p = p->next)
		{
			if (p->data.getBallance() >= ballance) {
				cout << p->data;
				existed = true;
			}
		}
		if (!existed) {
			cout << "<== Khong tim thay ket qua ==>\n";
		}
	}
	// hàm tìm kiếm theo tên chủ tài khoản
	void findByOwnerName(string name) {
		bool existed = false;
		for (auto p = head; p != nullptr; p = p->next)
		{
			string firstName = p->data.getOwner().substr(namePosition(p->data.getOwner()));
			transform(name.begin(), name.end(), name.begin(),
				[](unsigned char c) { return std::toupper(c); });
			if (firstName.compare(name) == 0) {
				existed = true;
				cout << p->data;
			}
		}
		if (!existed) {
			cout << "<== Khong tim thay ket qua ==>\n";
		}
	}
};

int main() {
	LinkedList accounts;
	// thêm vào đầu
	accounts.add(BankAccount("03301014669875", "TRAN VAN NAM", "MSB", 25000000, "01/01/2023"));
	accounts.add(BankAccount("03301014669870", "TRAN VAN PHONG", "MSB", 9000000, "14/01/2023"));
	accounts.add(BankAccount("03301014669878", "TRAN VAN HAI", "MSB", 25000000, "25/01/2023"));
	accounts.add(BankAccount("03301014669871", "TRAN VAN KHANH", "MSB", 11000000, "17/01/2023"));
	accounts.add(BankAccount("03301014669872", "TRAN VAN TRUNG", "MSB", 68000000, "14/01/2023"));
	accounts.add(BankAccount("03301014669874", "TRAN VAN TUNG", "MSB", 61000000, "19/01/2023"));
	accounts.add(BankAccount("03301014669873", "TRAN VAN KHAI", "MSB", 67000000, "10/01/2023"));
	accounts.add(BankAccount("03301014669876", "TRAN VAN TUAN", "MSB", 66000000, "15/01/2023"));
	accounts.add(BankAccount("03301014669879", "TRAN VAN LONG", "MSB", 66000000, "15/01/2023"));
	accounts.add(BankAccount("03301014669877", "TRAN VAN LUAN", "MSB", 66000000, "15/01/2023"));
	cout << "====== Danh sach tai khoan truoc khi sap xep: ======\n";
	accounts.showList();
	cout << "====================================================\n";
	cout << "Tim TK co so TK '03301014669876': " << endl;
	accounts.findByAccNumber("03301014669876");
	cout << "====================================================\n";
	string date;
	cout << "Nhap ngay phat hanh, vi du 20/10/2025: ";
	cin >> date;
	cout << "Cac tai khoan phat hanh vao ngay \"" << date << "\": \n";
	accounts.findByReleaseDate(date);
	cout << "====================================================\n";
	long amount;
	cout << "Nhap vao so du can tim: ";
	cin >> amount;
	cout << "Danh sach tai khoan co so du >= " << amount << endl;
	accounts.findByBallance(amount);
	cout << "====================================================\n";
	string name;
	cout << "Nhap ten tai khoan can tim: ";
	cin >> name;
	cout << "Danh sach cac TK co ten chu TK la \"" << name << "\": \n";
	accounts.findByOwnerName(name);

	return 0;
} 