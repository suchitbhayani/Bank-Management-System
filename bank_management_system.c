#include <stdio.h>
#include <stdbool.h> 

struct BankAccount {
    char username[20];
    char password[20];
    double balance;
};

struct BankAccount accounts[50];
int nextFreeAccount = 0;

void createAccount() {
    if (nextFreeAccount < 50) {
        printf("\nEnter username: \n");
        scanf("%s", accounts[nextFreeAccount].username);
        printf("\nEnter password: \n");
        scanf("%s", accounts[nextFreeAccount].password);
        accounts[nextFreeAccount].balance = 0.00;
        printf("\nAccount created. Balance is currently $%d\n\n", accounts[nextFreeAccount].balance);
        nextFreeAccount++;
    } else {
        printf("Too many accounts created!");
    }
}

int main() {
    bool keepRunning = true;
    char mainScreenInput;

    printf("Welcome to Bhayani Banking!\n");

    while (keepRunning) {
        printf("\nPlease select an action: \n");

        printf("(1) - Create account\n");
        printf("(2) - Login\n");
        printf("(X) - Exit\n\n");
        scanf(" %c", &mainScreenInput);
        
        switch(mainScreenInput) {
        case '1' :
            createAccount();
            break;
        case '2' :
            break;
        case 'X' :
            printf("Thank you for banking with us!\n");
            keepRunning = false;
            break;
        default :
            printf("Invalid input!\n");
            break;

        }

    }

    return 0;

}