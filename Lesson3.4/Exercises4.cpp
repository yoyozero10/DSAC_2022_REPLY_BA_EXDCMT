#include <iostream>
#include <string>
using namespace std;

class BankAccount {
	friend ostream& operator << (ostream&, const BankAccount&);
	string cardNum; // số thẻ
	string accNum; // số tài khoản
	string bankName; // ngân hàng phát hành
	long ballance; // số dư
	string owner; // chủ thẻ
public:
	BankAccount(string cardNum = "", string accNum = "",
		string owner = "", string bankName = "", long ballance = 0) {
		this->cardNum = cardNum;
		this->accNum = accNum;
		this->owner = owner;
		this->ballance = ballance;
		this->bankName = bankName;
	}

	void setCardNumber(string cardNum) {
		this->cardNum = cardNum;
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

	string getCardNum() {
		return cardNum;
	}

	bool operator == (const BankAccount& acc) {
		return cardNum.compare(acc.cardNum) == 0;
	}
};

ostream& operator << (ostream& os, const BankAccount& acc) {
	os << "[" << acc.cardNum << ", " << acc.owner << ", " << acc.accNum
		<< ", " << acc.bankName << ", " << acc.ballance << "]\n";
	return os;
}

class Node { // sử dụng lớp template
public:
	BankAccount data; // dữ liệu của node hiện tại
	Node* next; // con trỏ trỏ tới node kế tiếp
	Node* prev; // con trỏ trỏ tới node liền trước

	Node(BankAccount data) {
		this->next = nullptr; // khởi tạo mặc định khi tạo node
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

	// hàm cập nhật điểm và email theo mã sinh viên
	bool update(BankAccount data) {
		Node* p = head;
		while (p != nullptr) {
			if (p->data == data) {
				p->data.setBallance(data.getBallance());
				return true; // update success
			}
			p = p->next;
		}
		return false;
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
};

int main() {
	LinkedList accounts;
	// thêm vào đầu
	accounts.add(BankAccount("ACC01", "5114 0123 0123 0123", "TRAN VAN NAM", "MSB", 25000000));
	accounts.add(BankAccount("ACC02", "5114 0123 0123 0124", "TRAN VAN PHONG", "MSB", 99000000));
	accounts.add(BankAccount("ACC03", "5114 0123 0123 0125", "TRAN VAN HAI", "MSB", 85000000));
	accounts.add(BankAccount("ACC04", "5114 0123 0123 0120", "TRAN VAN KHANH", "MSB", 11000000));
	accounts.add(BankAccount("ACC05", "5114 0123 0123 0121", "TRAN VAN TRUNG", "MSB", 68000000));
	cout << "====== Danh sach truoc update: ======\n";
	accounts.showList();
	// update info
	accounts.update(BankAccount("ACC01", "", "", "", 53000000));
	cout << "====== Danh sach sau update TK ma \"ACC01\": ======\n";
	accounts.showList();

	return 0;
}