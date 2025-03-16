#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions.h"

int main() {
    int option;
    while (1) {
        printf("\033[31m-------------------------------------------------\n");
        printf("|\t\t\033[1mWelcome!\t\t\t|\n");
        printf("\033[31m-------------------------------------------------\n\n");

        printf("NOTE : Please Create the Account First (if you don't have)\n\n");

        printf("Please select an option: \n");
        printf("1 -> Go To ATM \n");
        printf("2 -> Create Account \n");
        printf("3 -> Exit \n");

        printf("Enter your Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (AccountCheck()) {
                    if (PinCheck()) {
                        UserChoice();
                    } else {
                        printf("Incorrect PIN\n");
                        exit(0);
                    }
                } else {
                    printf("\nThis Account Doesn't Exist\nPlease Correct Or Create an AccNumber\n");
                }
                break;

            case 2:
                NewAccount();
                break;

            case 3:
                printf("Exit!\n");
                exit(0);

            default:
                printf("Please Enter The Valid Option!\n");
                break;
        }

        printf("\nPress Enter to continue...\n\n");
        getchar();
        getchar();
    }
    return 0;
}