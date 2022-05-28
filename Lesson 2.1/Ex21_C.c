#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @author Branium Academy
* @version 2022.05.28
* @see htttps://braniumacademy.net
*/

typedef struct {
    char id[20];
    char owner[30];
    char accNumber[20];
    long ballance;
    char releaseDate[20];
    char bankName[20];
} BankAccount;

void getAccountInfo(BankAccount* acc) {
    printf("%s", "<=== Nhap thong tin tai khoan moi ===>\n");
    printf("%s", "Ma tai khoan: ");
    scanf("%20[^\n]", acc->id);
    printf("%s", "Ten chu the: ");
    scanf("%*c%30[^\n]", acc->owner);
    printf("%s", "So tai khoan: ");
    scanf("%*c%20[^\n]", acc->accNumber);
    printf("%s", "So du: ");
    scanf("%ld", &acc->ballance);
    printf("%s", "Ngay phat hanh: ");
    scanf("%*c");
    scanf("%*c%20[^\n]", acc->releaseDate);
    printf("%s", "Ngan hang phat hanh: ");
    scanf("%*c%20[^\n]", acc->bankName);
}

void deposit(BankAccount* acc) {
    printf("%s", "Nhap so tien muon nap vao tai khoan: ");
    long amount;
    scanf("%ld", &amount);
    if (amount > 0) {
        acc->ballance += amount;
        printf("%s", "<== Nap tien thanh cong! ==>\n");
    }
    else {
        printf("%s", "<== So tien can nap khong hop le ==>\n");
    }
}

void withdraw(BankAccount* acc) {
    printf("%s", "Nhap so tien muon rut: ");
    long amount;
    scanf("%ld", &amount);
    if (amount > 0 && amount < acc->ballance) {
        acc->ballance -= amount;
        printf("%s", "<== Rut tien thanh cong! ==>\n");
    }
    else {
        printf("%s", "<== So tien can rut khong hop le ==>\n");
    }
}

void showAccInfo(BankAccount* acc) {
    printf("%-10s%-20s%-30s%-20s%-20s%-20ld\n", acc->id, acc->accNumber,
        acc->owner, acc->bankName, acc->releaseDate, acc->ballance);
}

void transfer(BankAccount* acc1, BankAccount* acc2) {
    char acc1Number[20];
    char acc2Number[20];
    printf("%s", "Nhap so tai khoan nguon: ");
    scanf("%20[^\n]", acc1Number);
    printf("%s", "Nhap so tai khoan dich: ");
    scanf("%*c%20[^\n]", acc2Number);
    if (strcmp(acc1Number, acc2Number) == 0) {
        printf("%s", "<== Hai tai khoan can giao dich phai khac nhau ==>\n");
    }
    else if (strlen(acc1Number) == 0 ||
        (strcmp(acc1Number, acc1->accNumber) != 0 &&
            strcmp(acc1Number, acc2->accNumber) != 0)) {
        printf("%s", "<== Tai khoan nguon khong hop le ==>\n");
    }
    else if (strlen(acc2Number) == 0 ||
        (strcmp(acc2Number, acc1->accNumber) != 0 &&
            strcmp(acc2Number, acc2->accNumber) != 0)) {
        printf("%s", "<== Tai khoan dich khong hop le ==>\n");
    }
    else {
        printf("%s", "Nhap so tien can chuyen: ");
        long amount;
        scanf("%ld", &amount);
        if (amount > 0 && strcmp(acc1->accNumber, acc1Number) == 0 && acc1->ballance > amount) {
            acc1->ballance -= amount;
            acc2->ballance += amount;
            printf("%s", "<== Chuyen tien thanh cong! ==>\n");
        }
        else if (amount > 0 && strcmp(acc2->accNumber, acc1Number) == 0 && acc2->ballance > amount) {
            acc2->ballance -= amount;
            acc1->ballance += amount;
            printf("%s", "<== Chuyen tien thanh cong! ==>\n");
        }
        else {
            printf("%s", "<== So du khong du de thuc hien giao dich nay ==>\n");
        }
    }
}

void init(BankAccount* acc) {
    acc->accNumber[0] = '\0';
    acc->bankName[0] = '\0';
    acc->owner[0] = '\0';
    acc->releaseDate[0] = '\0';
    acc->ballance = 0;
    acc->id[0] = '\0';
}

int main()
{
    int choice;
    BankAccount* acc1 = (BankAccount*)malloc(sizeof(BankAccount)); // tai khoan thu nhat
    BankAccount* acc2 = (BankAccount*)malloc(sizeof(BankAccount)); // tai khoan thu hai
    init(acc1);
    init(acc2);

    do {
        printf("%s", "=============== OPTION ===============\n");
        printf("%s", "1. Tao moi tai khoan ngan hang.\n");
        printf("%s", "2. Hien thi thong tin cac tai khoan hien co.\n");
        printf("%s", "3. Nap tien vao tai khoan.\n");
        printf("%s", "4. Rut tien tu tai khoan hien co.\n");
        printf("%s", "5. Chuyen khoan ngan hang.\n");
        printf("%s", "6. Kiem tra so du.\n");
        printf("%s", "0. Thoat chuong trinh.\n");
        printf("%s", "Ban chon? ");
        scanf("%d", &choice);
        scanf("%*c"); // loại bỏ kí tự xuống dòng sau khi nhấn enter
        switch (choice)
        {
        case 0:
            printf("%s", "<== Cam on va hen gap lai ==>\n");
            break;
        case 1:
            getAccountInfo(acc1);
            getAccountInfo(acc2);
            break;
        case 2:printf("%-10s%-20s%-30s%-20s%-20s%-20s\n", "Ma TK", "So TK", "Chu TK", "Ten NH",
            "Nay phat hanh", "So du");
            showAccInfo(acc1);
            showAccInfo(acc2);
            break;
        case 3:
        {
            printf("%s", "Nhap so tai khoan: ");
            char accNumber[20];
            scanf("%20[^\n]", accNumber);
            if (strcmp(accNumber, acc1->accNumber) == 0) {
                deposit(acc1);
            }
            else if (strcmp(accNumber, acc2->accNumber) == 0) {
                deposit(acc2);
            }
            else {
                printf("%s", "<== Tai khoan khong ton tai. ==>\n");
            }
            break;
        }
        case 4: {
            printf("%s", "Nhap so tai khoan: ");
            char accNumber[20];
            scanf("%20[^\n]", accNumber);
            if (strcmp(accNumber, acc1->accNumber) == 0) {
                withdraw(acc1);
            }
            else if (strcmp(acc2->accNumber, accNumber) == 0) {
                withdraw(acc2);
            }
            else {
                printf("%s", "<== Tai khoan khong ton tai. ==>\n");
            }
            break;
        }
        case 5:
            transfer(acc1, acc2);
            break;
        case 6:
        {
            printf("%s", "Nhap so tai khoan: ");
            char accNumber[20];
            scanf("%20[^\n]", accNumber);
            if (strcmp(acc1->accNumber, accNumber) == 0) {
                showAccInfo(acc1);
            }
            else if (strcmp(acc2->accNumber, accNumber) == 0) {
                showAccInfo(acc2);
            }
            else {
                printf("%s", "<== Tai khoan khong ton tai. ==>\n");
            }
            break;
        }
        default:
            printf("%s", "<== Sai chuc nang, vui long chon lai! ==>\n");
            break;
        }
    } while (choice != 0);
    // giai phong bo nho
    free(acc1);
    free(acc2);

    return 0;
}
