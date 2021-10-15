#include <iostream>
#include <fstream>
using namespace std;

class Node {
	int level;
	int operand;

public:
	Node(int operand = 0, int level = -1) {
		this->level = level;
		this->operand = operand;
	}

	void setOperand(int op) {
		this->operand = op;
	}

	void setLevel(int level) {
		this->level = level;
	}

	int getOperand() {
		return operand;
	}

	int getLevel() {
		return level;
	}

	bool operator == (const Node& other) {
		return level == other.level;
	}
};
// khai báo hàm nguyên mẫu
int maxLevel(int np, int nq);
void mul(Node* p, Node* q, Node* product, int np, int nq, int nProduct);
void derivetive(Node* sum, Node* deri, int n);
void showData(Node* sum, int n);
void readData(Node* p, int n, ifstream& ifs);
void add(Node* p, Node* q, Node* sum, int np, int nq, int nSum);

int main() {
	ifstream ifs("input1.txt");
	if (ifs) {
        int t;
        ifs >> t;
        while (t-- > 0) {
            int np;
            int nq;
            ifs >> np;
            Node* p = new Node[np + 1]();
            readData(p, np, ifs);
            ifs >> nq;
            int nProduct = np + nq;
            Node* q = new Node[nq + 1]();
            readData(q, nq, ifs);
            int nSum = maxLevel(np, nq);
            Node* sum = new Node[nSum + 1]();
            add(p, q, sum, np, nq, nSum);
            Node* deri = new Node[nSum];
            derivetive(sum, deri, nSum);
            Node* product = new Node[nProduct + 1]();
            mul(p, q, product, np, nq, nProduct);
            showData(sum, nSum);
            showData(deri, nSum - 1);
            showData(product, nProduct);
            ifs.close();
        }
	}
	return 0;
}

void mul(Node* p, Node* q, Node* product, int np, int nq, int nProduct) {
    for (int i = 0; i <= np; i++) {
        for (int j = 0; j <= nq; j++) {
            int operand = p[i].getOperand() * q[j].getOperand();
            int level = p[i].getLevel() + q[j].getLevel();
            if (product[level].getLevel() != -1) {
                product[level].setOperand(operand + product[level].getOperand());
            }
            else {
                product[level] = Node(operand, level);
            }
        }
    }
}

/**
 * Phương thức tính đạo hàm của đa thức tổng
 *
 * @param sum đa thức tổng cần tính đạo hàm
 * @return đạo hàm bậc nhất của đa thức tổng
 */
void derivetive(Node* sum, Node* result, int n) {
    for (int i = 1; i <= n; i++) {
        result[i - 1] = Node(sum[i].getOperand() * sum[i].getLevel(),
            sum[i].getLevel() - 1);
    }
}

void showData(Node* sum, int n) {
    for (int i = n; i >= 0; i--) {
        cout << sum[i].getOperand() << " ";
    }
    cout << endl;
}

void readData(Node* p, int n, ifstream& ifs) {
    for (int i = n; i >= 0; i--) {
        int op;
        ifs >> op;
        Node node(op, i);
        p[i] = node;
    }
}

void add(Node* p, Node* q, Node* sum, int np, int nq, int nSum) {
    int n1 = np;
    int n2 = nq;
    while (n1 >= 0 && n2 >= 0) {
        if (p[n1].getLevel() == q[n2].getLevel()) {
            sum[nSum--] = Node(p[n1].getOperand() + q[n2].getOperand(),
                p[n1].getLevel());
            n1--;
            n2--;
        }
        else if (p[n1].getLevel() > q[n2].getLevel()) {
            sum[nSum--] = Node(p[n1].getOperand(), p[n1].getLevel());
            n1--;
        }
        else {
            sum[nSum--] = Node(q[n2].getOperand(), q[n2].getLevel());
            n2--;
        }
    }
    while (n1 >= 0) {
        sum[nSum--] = Node(p[n1].getOperand(), p[n1].getLevel());
        n1--;
    }
    while (n2 >= 0) {
        sum[nSum--] = Node(q[n2].getOperand(), q[n2].getLevel());
        n2--;
    }
}

int maxLevel(int np, int nq) {
    int max = np;
    if (np < nq) {
        max = nq;
    }
    return max;
}