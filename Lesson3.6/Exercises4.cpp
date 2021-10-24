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
	string cardNum; // số thẻ
	string accNum; // số tài khoản
	string bankName; // ngân hàng phát hành
	long ballance; // số dư
	string owner; // chủ thẻ
	string startDate; // ngày phát hành
	string endDate; // ngày hết hạn
	string cardType; // loại thẻ
public:
	BankAccount(string accNum = "", string cardNum = "",
		string owner = "", string bankName = "", long ballance = 0, 
		string start = "1/1/2020", string end = "31/12/2025", string type = "Debit") {
		this->cardNum = cardNum;
		this->accNum = accNum;
		this->owner = owner;
		this->ballance = ballance;
		this->bankName = bankName;
		this->startDate = start;
		this->endDate = end;
		this->cardType = type;
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

	string getStartDate() {
		return startDate;
	}

	string getEndDate() {
		return endDate;
	}

	void setStartDate(string start) {
		startDate = start;
	}

	void setEndDate(string end) {
		endDate = end;
	}

	string getCardType() {
		return cardType;
	}

	void setCardType(string cardType) {
		this->cardType = cardType;
	}

	bool operator == (const BankAccount& acc) {
		return cardNum.compare(acc.cardNum) == 0;
	}
};

ostream& operator << (ostream& os, const BankAccount& acc) {
	os << left << setw(8) << acc.accNum << setw(22) << acc.owner << setw(20) 
		<< acc.cardNum << setw(10) << acc.bankName << setw(12) << acc.ballance
		<< setw(12) << acc.startDate << setw(12) << acc.endDate 
		<< setw(12) << acc.cardType << endl;
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

	// xóa tài khoản có số tài khoản x
	bool removeByAccNum(string accNum) {
		Node* p = head;
		while (p != nullptr) {
			if (p->data.getAccNum().compare(accNum) == 0) {
				if (p == head) {
					removeHead();
				}
				else if (p == tail) {
					removeTail(p->prev);
				}
				else {
					Node* r = p;
					Node* prevP = p->prev;
					Node* nextP = p->next;
					prevP->next = nextP;
					nextP->prev = prevP;
					delete r;
				}
				return true; // xóa thành công
			}
			p = p->next;
		}
		return false; // xóa thất bại
	}
	// xóa tài khoản có số thẻ x
	bool removeByCardNumber(string cardNum) {
		Node* p = head;
		while (p != nullptr) {
			if (p->data.getCardNum().compare(cardNum) == 0) {
				if (p == head) {
					removeHead();
				}
				else if (p == tail) {
					removeTail(p->prev);
				}
				else {
					Node* r = p;
					Node* prevP = p->prev;
					Node* nextP = p->next;
					prevP->next = nextP;
					nextP->prev = prevP;
					delete r;
				}
				return true; // xóa thành công
			}
			p = p->next;
		}
		return false; // xóa thất bại
	}
	// xóa tất cả các tài khoản có số dư nhỏ hơn x
	void removeByBallance(long ballance) {
		if (isEmpty()) {
			cout << "Danh sach rong.\n";
			return;
		}
		Node* x = head;
		Node* prevX = head;
		while (x != nullptr) {
			if (x->data.getBallance() < ballance) {
				if (x == head) {
					removeHead();
					x = head; // cập nhật lại x
					continue;
				}
				else if (x == tail) {
					removeTail(prevX);
					x = tail;
					continue;
				}
				else if (x != nullptr) {
					prevX->next = x->next;
					Node* r = x;
					x = x->next;
					if (x != nullptr) {
						x->prev = prevX;
					}
					delete r;
					continue;
				}
			}
			prevX = x;
			x = x->next;
		}
	}
	// xóa tất cả các tài khoản hết hạn sử dụng vào ngày x
	void removeExpiredAcc(string expiredDate) {
		if (isEmpty()) {
			cout << "Danh sach rong.\n";
			return;
		}
		Node* x = head;
		Node* prevX = head;
		while (x != nullptr) {
			if (x->data.getEndDate().compare(expiredDate) == 0) {
				if (x == head) {
					removeHead();
					x = head; // cập nhật lại x
					continue;
				}
				else if (x == tail) {
					removeTail(prevX);
					x = tail;
					continue;
				}
				else if (x != nullptr) {
					prevX->next = x->next;
					Node* r = x;
					x = x->next;
					if (x != nullptr) {
						x->prev = prevX;
					}
					delete r;
					continue;
				}
			}
			prevX = x;
			x = x->next;
		}
	}
	// hàm xóa node ở đầu danh sách
	bool removeHead() {
		Node* r = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		delete r;
		return true;
	}
	// hàm xóa node ở cuối danh sách
	bool removeTail(Node* prevX) {
		Node* r = tail;
		if (prevX != nullptr) {
			prevX->next = nullptr;
		}
		tail = prevX;
		delete r;
		return true;
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
	accounts.add(BankAccount("ACC01", "5114 0123 0123 0123", "TRAN VAN NAM", "MSB", 25000000, "1/1/2023", "1/1/2027"));
	accounts.add(BankAccount("ACC02", "5114 0123 0123 0124", "TRAN VAN PHONG", "MSB", 9000000, "14/1/2023", "14/1/2027"));
	accounts.add(BankAccount("ACC03", "5114 0123 0123 0125", "TRAN VAN HAI", "MSB", 25000000, "25/1/2023", "25/1/2027"));
	accounts.add(BankAccount("ACC04", "5114 0123 0123 0120", "TRAN VAN KHANH", "MSB", 11000000, "17/1/2023", "17/1/2027"));
	accounts.add(BankAccount("ACC05", "5114 0123 0123 0121", "TRAN VAN TRUNG", "MSB", 68000000, "20/1/2023", "14/1/2027"));
	accounts.add(BankAccount("ACC06", "5114 0123 0123 0122", "TRAN VAN TUNG", "MSB", 61000000, "19/1/2023", "19/1/2027"));
	accounts.add(BankAccount("ACC07", "5114 0123 0123 0126", "TRAN VAN KHAI", "MSB", 67000000, "10/1/2023", "10/1/2027"));
	accounts.add(BankAccount("ACC08", "5114 0123 0123 0127", "TRAN VAN LUAN", "MSB", 66000000, "15/1/2023", "15/1/2027"));
	cout << "====== Danh sach truoc khi xoa: ======\n";
	accounts.showList();

	// xóa tài khoản có số thẻ x
	accounts.removeByCardNumber("5114 0123 0123 0123");
	cout << "====== Danh sach sau xoa TK co so the \"5114 0123 0123 0123\": ======\n";
	accounts.showList();

	// xóa tài khoản có số tk
	accounts.removeByAccNum("ACC04");
	cout << "====== Danh sach sau xoa TK co so tk \"ACC04\": ======\n";
	accounts.showList();

	// xóa tài khoản có số dư nhỏ hơn 50.000.000đ
	accounts.removeByBallance(50000000);
	cout << "====== Danh sach sau xoa TK co so du nho hon 50tr: ======\n";
	accounts.showList();

	// xóa tài khoản hết hạn vào ngày x
	accounts.removeExpiredAcc("14/1/2027");
	cout << "====== Danh sach sau xoa TK co so du nho hon 50tr: ======\n";
	accounts.showList();

	return 0;
}