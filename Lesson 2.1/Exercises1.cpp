/**
* @author Branium Academy
* @version 2022.05.28
* @see https://braniumacademy.net
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct {
    string id;
    string owner;
    string accNumber;
    long ballance;
    string releaseDate;
    string bankName;
} BankAccount;

void getAccountInfo(BankAccount* acc) {
    cout << "<=== Nhap thong tin tai khoan moi ===>\n";
    cout << "Ma tai khoan: ";
    getline(cin, acc->id);
    cout << "Ten chu the: ";
    getline(cin, acc->owner);
    cout << "So tai khoan: ";
    getline(cin, acc->accNumber);
    cout << "So du: ";
    cin >> acc->ballance;
    cout << "Ngay phat hanh: ";
    cin.ignore();
    getline(cin, acc->releaseDate);
    cout << "Ngan hang phat hanh: ";
    getline(cin, acc->bankName);
}

void deposit(BankAccount* acc) {
    cout << "Nhap so tien muon nap vao tai khoan: ";
    long amount;
    cin >> amount;
    if (amount > 0) {
        acc->ballance += amount;
        cout << "<== Nap tien thanh cong! ==>\n";
    } else{
        cout << "<== So tien can nap khong hop le ==>\n";
    }
}

void withdraw(BankAccount* acc) {
    cout << "Nhap so tien muon rut: ";
    long amount;
    cin >> amount;
    if (amount > 0 && amount < acc->ballance) {
        acc->ballance -= amount;
        cout << "<== Rut tien thanh cong! ==>\n";
    }
    else {
        cout << "<== So tien can rut khong hop le ==>\n";
    }
}

void showAccInfo(BankAccount* acc) {
    cout << left << setw(10) << acc->id << setw(20) << acc->accNumber
        << setw(30) << acc->owner << setw(20) << acc->bankName
        << setw(20) << acc->releaseDate << setw(20) << acc->ballance << endl;
}

void transfer(BankAccount* acc1, BankAccount* acc2) {
    string acc1Number;
    string acc2Number;
    cout << "Nhap so tai khoan nguon: ";
    getline(cin, acc1Number);
    cout << "Nhap so tai khoan dich: ";
    getline(cin, acc2Number);
    if (acc1Number.compare(acc2Number) == 0) {
        cout << "<== Hai tai khoan can giao dich phai khac nhau ==>\n";
    }
    else if (acc1Number.length() == 0 || 
        (acc1Number.compare(acc1->accNumber) != 0 && 
        acc1Number.compare(acc2->accNumber) != 0)) {
        cout << "<== Tai khoan nguon khong hop le ==>\n";
    }
    else if (acc2Number.length() == 0 ||
        (acc2Number.compare(acc1->accNumber) != 0 &&
        acc2Number.compare(acc2->accNumber) != 0)) {
        cout << "<== Tai khoan dich khong hop le ==>\n";
    }
    else {
        cout << "Nhap so tien can chuyen: ";
        long amount;
        cin >> amount;
        if (amount> 0 && acc1->accNumber.compare(acc1Number) == 0 && acc1->ballance > amount) {
            acc1->ballance -= amount;
            acc2->ballance += amount;
            cout << "<== Chuyen tien thanh cong! ==>\n";
        }
        else if (amount > 0 && acc2->accNumber.compare(acc1Number) == 0 && acc2->ballance > amount) {
            acc2->ballance -= amount;
            acc1->ballance += amount;
            cout << "<== Chuyen tien thanh cong! ==>\n";
        }
        else {
            cout << "<== So du khong du de thuc hien giao dich nay ==>\n";
        }
    }
}

int main()
{
    int choice;
    BankAccount* acc1 = new BankAccount(); // tai khoan thu nhat
    BankAccount* acc2 = new BankAccount(); // tai khoan thu hai
    do {
        cout << "=============== OPTION ===============\n";
        cout << "1. Tao moi tai khoan ngan hang.\n";
        cout << "2. Hien thi thong tin cac tai khoan hien co.\n";
        cout << "3. Nap tien vao tai khoan.\n";
        cout << "4. Rut tien tu tai khoan hien co.\n";
        cout << "5. Chuyen khoan ngan hang.\n";
        cout << "6. Kiem tra so du.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "Ban chon? ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
            cout << "<== Cam on va hen gap lai ==>\n";
            break;
        case 1:
            getAccountInfo(acc1);
            getAccountInfo(acc2);
            break;
        case 2:cout << left << setw(10) << "Ma TK" << setw(20) << "So TK"
            << setw(30) << "Chu TK" << setw(20) << "Ten NH"
            << setw(20) << "Nay phat hanh" << setw(20) << "So du" << endl;
            showAccInfo(acc1);
            showAccInfo(acc2);
            break;
        case 3:
        {
            cout << "Nhap so tai khoan: ";
            string accNumber;
            getline(cin, accNumber);
            if (acc1->accNumber.compare(accNumber) == 0) {
                deposit(acc1);
            }
            else if (acc2->accNumber.compare(accNumber) == 0) {
                deposit(acc2);
            }
            else {
                cout << "<== Tai khoan khong ton tai. ==>\n";
            }
            break;
        }
        case 4: {
            cout << "Nhap so tai khoan: ";
            string accNumber;
            getline(cin, accNumber);
            if (acc1->accNumber.compare(accNumber) == 0) {
                withdraw(acc1);
            }
            else if (acc2->accNumber.compare(accNumber) == 0) {
                withdraw(acc2);
            }
            else {
                cout << "<== Tai khoan khong ton tai. ==>\n";
            }
            break;
        }
        case 5:
            transfer(acc1, acc2);
            break;
        case 6:
        {
            cout << "Nhap so tai khoan: ";
            string accNumber;
            getline(cin, accNumber);
            if (acc1->accNumber.compare(accNumber) == 0) {
                showAccInfo(acc1);
            }
            else if (acc2->accNumber.compare(accNumber) == 0) {
                showAccInfo(acc2);
            }
            else {
                cout << "<== Tai khoan khong ton tai. ==>\n";
            }
            break;
        }
        default:
            cout << "<== Sai chuc nang, vui long chon lai! ==>\n";
            break;
        }
    } while (choice != 0);
    // giai phong bo nho
    delete acc1;
    delete acc2;

    return 0;
}
