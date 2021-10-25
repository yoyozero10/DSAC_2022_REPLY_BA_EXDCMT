/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.10
 *
 */
#include <iostream>
#include <iomanip>
#include <string>
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
		string start = "1/1/2020") {
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
	os << left << setw(8) << acc.accNum << setw(22) << acc.owner 
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

	// hàm sắp xếp theo tên chủ tài khoản
	void sortByOwnerName() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getOwner().substr(namePosition(q->data.getOwner()))
					.compare(p->data.getOwner().substr(namePosition(p->data.getOwner()))) < 0) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
	// hàm sắp xếp số tài khoản từ z-a
	void sortByAccNumber() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getAccNum().compare(p->data.getAccNum()) > 0) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
	// sắp xếp theo ngày phát hành từ cũ đến mới
	void sortByAccReleaseDate() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (getYear(q->data.getStartDate()) < getYear(p->data.getStartDate()) ||
					getYear(q->data.getStartDate()) == getYear(p->data.getStartDate()) && 
					getMonth(q->data.getStartDate()) < getMonth(p->data.getStartDate()) || 
					getYear(q->data.getStartDate()) == getYear(p->data.getStartDate()) &&
					getMonth(q->data.getStartDate()) == getMonth(p->data.getStartDate()) &&
					getDay(q->data.getStartDate()) < getDay(p->data.getStartDate())) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
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

	// hàm sắp xếp theo số dư giảm dần
	void sortByBallance() {
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next)
			{
				if (q->data.getBallance() > p->data.getBallance() ||
					q->data.getBallance() == p->data.getBallance() &&
					q->data.getOwner().substr(namePosition(q->data.getOwner()))
					.compare(p->data.getOwner().substr(namePosition(p->data.getOwner()))) < 0) {
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
};

int main() {
	LinkedList accounts;
	// thêm vào đầu
	accounts.add(BankAccount("ACC01", "TRAN VAN NAM", "MSB", 25000000, "01/01/2023"));
	accounts.add(BankAccount("ACC02", "TRAN VAN PHONG", "MSB", 9000000, "14/01/2023"));
	accounts.add(BankAccount("ACC03", "TRAN VAN HAI", "MSB", 25000000, "25/01/2023"));
	accounts.add(BankAccount("ACC04", "TRAN VAN KHANH", "MSB", 11000000, "17/01/2023"));
	accounts.add(BankAccount("ACC05", "TRAN VAN TRUNG", "MSB", 68000000, "14/01/2023"));
	accounts.add(BankAccount("ACC06", "TRAN VAN TUNG", "MSB", 61000000, "19/01/2023"));
	accounts.add(BankAccount("ACC07", "TRAN VAN KHAI", "MSB", 67000000, "10/01/2023"));
	accounts.add(BankAccount("ACC08", "TRAN VAN TUAN", "MSB", 66000000, "15/01/2023"));
	accounts.add(BankAccount("ACC08", "TRAN VAN LONG", "MSB", 66000000, "15/01/2023"));
	accounts.add(BankAccount("ACC08", "TRAN VAN LUAN", "MSB", 66000000, "15/01/2023"));
	cout << "====== Danh sach tai khoan truoc khi sap xep: ======\n";
	accounts.showList();
	cout << "====================================================\n";
	accounts.sortByOwnerName();
	cout << "Sau khi sap xep theo ten chu TK: \n";
	accounts.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo so TK: \n";
	accounts.sortByAccNumber();
	accounts.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo ngay phat hanh: \n";
	accounts.sortByAccReleaseDate();
	accounts.showList();
	cout << "====================================================\n";
	cout << "Sau khi sap xep theo so du giam dan: \n";
	accounts.sortByBallance();
	accounts.showList();

	return 0;
} 