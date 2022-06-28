#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// tạo node
struct Node {
    int data; // phần dữ liệu của node
    struct Node* nextPtr; // con trỏ trỏ đến địa chỉ node kế tiếp
};

// đặt biệt danh
typedef struct Node Node;

// tạo danh sách liên kết đơn
 typedef struct {
    Node* headPtr;
    Node* tailPtr;
} LinkedList;

// khởi tạo
void init(LinkedList* list) {
    list->headPtr = NULL;
    list->tailPtr = NULL;
}

// tạo node mới
Node* createNode(int data) {
    Node* p = (Node*)malloc(sizeof(Node));
    if(p != NULL) {
        p->data = data;
        p->nextPtr = NULL;
        return p;
    }
    return NULL;
}

// kiểm tra dslk rỗng không
bool isEmpty(LinkedList list) {
    return list.headPtr == NULL && list.tailPtr == NULL;
}

// thêm vào đầu dslk
void addHead(LinkedList* list, int data) {
    Node* p = createNode(data);
    if(p != NULL) {
        if(isEmpty(*list)) {
            list->headPtr = p;
            list->tailPtr = p;
        } else {
            p->nextPtr = list->headPtr;
            list->headPtr = p;
        }
        //puts("==> Chèn node vào đầu DSLK thành công.");
    } else {
        //puts("==> Không thể cấp phát. Chèn node vào đầu DSLK thất bại.");
    }
}

// chèn vào cuối danh sách
void addTail(LinkedList* list, int data) {
    if(isEmpty(*list)) {
        addHead(list, data);
    } else {
        Node* p = createNode(data);
        if(p != NULL) {
            list->tailPtr->nextPtr = p;
            list->tailPtr = p;
            //puts("==> Chèn node vào cuối DSLK thành công.");
        } else {
            //puts("==> Không thể cấp phát. Chèn node vào cuối DSLK thất bại.");
        }
    }
}

// chèn node vào sau node đầu tiên có giá trị x
void addAfterX(LinkedList* list, int data, int x) {
    if(isEmpty(*list)) {
        addHead(list, data);
    } else if(list->tailPtr->data == x) {
        addTail(list, data);
    } else {
        Node* keyNode = list->headPtr;
        while (keyNode != NULL) {
            if(keyNode->data ==  x) {
                break;
            }
            keyNode = keyNode->nextPtr;
        }
        if(keyNode == NULL) {
            printf("==> Không tìm thấy node có giá trị x = %d.\n", x);
        } else {
            Node* p = createNode(data);
            if(p != NULL) {
                p->nextPtr = keyNode->nextPtr;
                keyNode->nextPtr = p;
                puts("==> Thêm node thành công.");
            } else {
                puts("==> Không thể cấp phát. Thêm node thất bại.");
            }
        }
    }
}

// duyệt danh sách liên kết
void showNodes(LinkedList list) {
    Node* p = list.headPtr;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->nextPtr;
    }
    printf("%s", "NULL\n");
}

// tìm node có giá trị x
bool findNodeX(LinkedList list, int x) {
    Node *p = list.headPtr;
    while (p != NULL) {
        if(p->data == x) { // đã tìm thấy x
            return true; // trả về kết quả đã tìm thấy x
        }
        p = p->nextPtr;
    }
    return false; // không tìm thấy x trong DSLK
}

// đếm số lần xuất hiện của node có giá trị x
int countNodeX(LinkedList list, int x) {
    int counter = 0;
    Node *p = list.headPtr;
    while (p != NULL) {
        if(p->data == x) { // đã tìm thấy x
            counter++; // tăng giá trị biến đếm số lần xuất hiện của x trong DSLK
        }
        p = p->nextPtr; // cập nhật p
    }
    return counter; // trả về kết quả
}

// cập nhật giá trị cho node đầu tiên có giá trị x trong danh sách liên kết
void updateNodeX(LinkedList* list, int x, int newX) {
    Node* p = list->headPtr;
    bool isSuccess = false;
    while (p != NULL) {
        if(p->data == x) {
            p->data = newX;
            puts("==> Cập nhật thành công.");
            isSuccess = true;
            break;
        }
        p = p->nextPtr;
    }
    if(!isSuccess) {
        printf("==> Không tìm thấy node với giá trị x = %d. Cập nhật thất bại.\n", x);
    }
}

// cập nhật tất cả node có giá trị x trong danh sách liên kết
int updateAllX(LinkedList* list, int x, int newX) {
    Node* p = list->headPtr;
    int numberOfNodeUpdated = 0;
    while (p != NULL) {
        if(p->data == x) {
            p->data = newX;
            //puts("==> Cập nhật thành công.");
            numberOfNodeUpdated++;
        }
        p = p->nextPtr;
    }
    return numberOfNodeUpdated;
}

int main() {
    LinkedList list; // khai báo DSLK đơn
    init(&list); // gọi hàm khởi tạo DSLK đơn
    
    // thêm vào đầu danh sách
    for (int i = 1; i <= 10; i++) {
        addHead(&list, i);
    }
    addTail(&list, 10);
    
    puts("==> Các node trong DSLK đơn: ");
    showNodes(list);
    
    // cập nhật
    int x = 3;
    printf("==> Cập nhật node x = %d\n", x);
    updateNodeX(&list, x, 300);
    x = 10;
    printf("==> Cập nhật node x = %d\n", x);
    int numOfupdatedNode = updateAllX(&list, x, 500);
    printf("==> Số lượng node được cập nhật: %d\n", numOfupdatedNode);
    
    puts("==> Các node trong DSLK sau khi cập nhật: ");
    showNodes(list);
}