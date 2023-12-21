#include <stdio.h>
#include <stdbool.h> 
#include <string.h>

struct BankAccount {
    char username[20];
    char password[20];
    double balance;
};

struct BankAccount accounts[50];
const size_t accountsSize = sizeof(accounts) / sizeof(accounts[0]);
int nextFreeAccount = 0;


void createAccount() {
    if (nextFreeAccount < accountsSize) {
        printf("\nEnter new username: \n");
        scanf("%s", accounts[nextFreeAccount].username);
        printf("\nEnter new password: \n");
        scanf("%s", accounts[nextFreeAccount].password);
        accounts[nextFreeAccount].balance = 0.00;
        printf("\nAccount created. Balance is currently $%d\n\n", accounts[nextFreeAccount].balance);

        printf("%s", accounts[nextFreeAccount].username);

        nextFreeAccount++;

    } else {
        printf("Too many accounts created!");
    }
}


bool accountExistsUserPass(char* username, char* password) {   
    for (int i = 0; i < accountsSize; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            return true;
        }
    }

    return false;
    
}


void login() {
    char enteredUser[20];
    char enteredPassword[20];

    printf("\nEnter username:\n");
    scanf("%s", enteredUser);
    printf("\nEnter password\n");
    scanf("%s", enteredPassword);

    if (accountExistsUserPass(enteredUser, enteredPassword)) {
        // launch login menu
    } else {
        printf("\nSorry, account does not exist!\n");
    }
}

int main() {
    bool keepRunning = true;
    char mainScreenInput;

    printf("Welcome to Bhayani Banking!\n");

    while (keepRunning) {
        printf("\nPlease select an action: \n\n");

        printf("(1) - Create account\n");
        printf("(2) - Login\n");
        printf("(X) - Exit\n\n");
        scanf(" %c", &mainScreenInput);
        
        switch(mainScreenInput) {
        case '1' :
            createAccount();
            break;
        case '2' :
            login();
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