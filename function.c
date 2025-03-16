#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions.h"

struct uservar {
    char name[30];
    char bankName[30];
    char city[30];
    int age;
    int mobileNum;
    int pin;
    int balance;
    int accountNum;
    int choice;
};

struct transaction {
    char type[20];
    int amount;
    int targetAccount;
};

struct uservar user;
struct transaction transactions[100];
int transactionCount = 0;

int AccountCheck() {
    int chkAcc;

    printf("-------------------------------------------------\n");
    printf("|\t\tEnter your AccNum\t\t|\n");
    printf("-------------------------------------------------\n\n");
    printf("-> Enter Account Number: ");
    scanf("%d", &chkAcc);

    if (user.accountNum == chkAcc) {
        return 1;
    } else {
        return 0;
    }
}

int PinCheck() {
    int chkpin;

    printf("-------------------------------------------------\n");
    printf("|\t\tEnter your Pin\t\t|\n");
    printf("-------------------------------------------------\n\n");
    printf("-> Enter Pin: ");
    scanf("%d", &chkpin);

    if (user.pin == chkpin) {
        return 1;
    } else {
        return 0;
    }
}

int OldPinCheck() {
    int chkpin;

    printf("-------------------------------------------------\n");
    printf("|\t\tEnter your Pin\t\t|\n");
    printf("-------------------------------------------------\n\n");
    printf("-> Enter Your Old Pin: ");
    scanf("%d", &chkpin);

    if (user.pin == chkpin) {
        return 1;
    } else {
        return 0;
    }
}

int UserChoice() {
    int choice;
    while (1) {
        printf("\n-------------------------------------------------\n");
        printf("|\t\tATM MENU\t\t|\n");
        printf("-------------------------------------------------\n\n");

        printf("1 -> Cash Withdrawal \n");
        printf("2 -> Cash Deposit \n");
        printf("3 -> View Account Details \n");
        printf("4 -> View Balance \n");
        printf("5 -> Change Pin Number \n");
        printf("6 -> Transfer Money \n");
        printf("7 -> View Transaction History \n");
        printf("8 -> Exit \n");

        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Withdraw();
                break;

            case 2:
                Deposite();
                break;

            case 3:
                Account();
                break;

            case 4:
                Balance();
                break;

            case 5:
                ChangePin();
                break;

            case 6:
                Transfer();
                break;

            case 7:
                TransactionHistory();
                break;

            case 8:
                printf("Exiting ATM Menu...\n");
                return 0;

            default:
                printf("Please Enter The Valid Option!\n");
        }

        printf("\nPress Enter to continue...\n");
        getchar();
        getchar();
    }
}

int Withdraw() {
    int cash = 0;

    printf("-------------------------------------------------\n");
    printf("|\t\tCASH WITHDRAWAL\t\t|\n");
    printf("-------------------------------------------------\n\n");

    printf("Enter the amount to Withdraw: ");
    scanf("%d", &cash);

    if (cash <= user.balance) {
        user.balance -= cash;
        strcpy(transactions[transactionCount].type, "Withdraw");
        transactions[transactionCount].amount = cash;
        transactionCount++;

        printf("Cash Withdrawn Successfully...\n");
        printf("Your Balance : %d\n", user.balance);
    } else {
        printf("Insufficient Balance!\n");
    }
}

int Deposite() {
    int cash = 0;

    printf("-------------------------------------------------\n");
    printf("|\t\tCASH DEPOSIT\t\t|\n");
    printf("-------------------------------------------------\n\n");

    printf("Enter the amount to Deposit: ");
    scanf("%d", &cash);

    user.balance = (cash + user.balance);
    strcpy(transactions[transactionCount].type, "Deposit");
    transactions[transactionCount].amount = cash;
    transactionCount++;

    printf("Cash Deposited Successfully...\n");
    printf("Your Balance : %d\n", user.balance);
}

int Balance() {
    printf("-------------------------------------------------\n");
    printf("|\t\tBALANCE CHECK\t\t|\n");
    printf("-------------------------------------------------\n\n");

    printf("Your Account Balance is: %d\n", user.balance);
}

int Account() {
    printf("-------------------------------------------------\n");
    printf("|\t\tACCOUNT DETAILS\t\t|\n");
    printf("-------------------------------------------------\n\n");

    printf("Account Holder Name: %s\n", user.name);
    printf("Account Holder Age: %d\n", user.age);
    printf("Account Number: %d\n", user.accountNum);
    printf("Account Holder Bank Name: %s\n", user.bankName);
    printf("Account Holder City: %s\n", user.city);
    printf("Account Holder Mobile Number: %d\n", user.mobileNum);
}

int ChangePin() {
    int newpin, confirmpin;

    if (OldPinCheck()) {
        printf("-------------------------------------------------\n");
        printf("|\t\tCHANGE PIN\t\t|\n");
        printf("-------------------------------------------------\n\n");

        printf("Enter New Pin Number: ");
        scanf("%d", &newpin);
        printf("\n");

        printf("Confirm New Pin Number: ");
        scanf("%d", &confirmpin);
        printf("\n");

        if (newpin == confirmpin) {
            user.pin = newpin;
            printf("Successfully Updated the New Pin Number\n");
        } else {
            printf("PINs do not match. Please try again.\n");
        }
    } else {
        printf("Incorrect PIN\n");
    }
}

int NewAccount() {
    int randomnum = 0;

    printf("-------------------------------------------------\n");
    printf("|\t\tCREATE NEW ACCOUNT\t\t|\n");
    printf("-------------------------------------------------\n\n");

    printf("Enter Your Name: ");
    scanf("%s", user.name);
    printf("Enter Your Age: ");
    scanf("%d", &user.age);
    printf("Enter Your Account Number: ");
    scanf("%d", &user.accountNum);
    printf("Enter Your Mobile Number: ");
    scanf("%d", &user.mobileNum);
    printf("Enter Your Bank Name: ");
    scanf("%s", user.bankName);
    printf("Enter Your City: ");
    scanf("%s", user.city);

    srand(time(0));
    randomnum = 1000 + (rand() % 9000);
    user.pin = randomnum;

    printf("Account Created Successfully \n");
    Account();
    DisplayPassword();
}

void DisplayPassword() {
    printf("\nThis is your password: %d\n", user.pin);
    printf("Please keep it safe!\n\n");
}

int Transfer() {
    int targetAccount, amount;

    printf("-------------------------------------------------\n");
    printf("|\t\tTRANSFER MONEY\t\t|\n");
    printf("-------------------------------------------------\n\n");

    printf("Enter Target Account Number: ");
    scanf("%d", &targetAccount);
    printf("Enter Amount to Transfer: ");
    scanf("%d", &amount);

    if (amount <= user.balance) {
        user.balance -= amount;
        strcpy(transactions[transactionCount].type, "Transfer");
        transactions[transactionCount].amount = amount;
        transactions[transactionCount].targetAccount = targetAccount;
        transactionCount++;

        printf("Amount Transferred Successfully...\n");
        printf("Your Balance : %d\n", user.balance);
    } else {
        printf("Insufficient Balance!\n");
    }
}

int TransactionHistory() {
    printf("-------------------------------------------------\n");
    printf("|\t\tTRANSACTION HISTORY\t\t|\n");
    printf("-------------------------------------------------\n\n");

    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Transfer") == 0) {
            printf("Type: %s, Amount: %d, Target Account: %d\n", transactions[i].type, transactions[i].amount, transactions[i].targetAccount);
        } else {
            printf("Type: %s, Amount: %d\n", transactions[i].type, transactions[i].amount);
        }
    }
}