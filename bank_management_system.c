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


bool usernameExists(char* username) {
    for (int i = 0; i < accountsSize; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return true;
        }
    }

    return false;
}

bool accountExistsUserPass(char* username, char* password) {   
    for (int i = 0; i < accountsSize; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            return true;
        }
    }

    // implement HashMap for efficiency?

    return false;
    
}

void createAccount() {
    if (nextFreeAccount < accountsSize) {
        char enteredUsername[20];
        char enteredPassword[20];
        printf("\nEnter new username: \n");
        scanf("%s", enteredUsername);
        printf("\nEnter new password: \n");
        scanf("%s", enteredPassword);

        if (!usernameExists(enteredUsername)) {
            strcpy(accounts[nextFreeAccount].username, enteredUsername);
            strcpy(accounts[nextFreeAccount].password, enteredPassword);
            accounts[nextFreeAccount].balance = 0.00;

            printf("\nAccount created. Balance is currently $%d\n\n", accounts[nextFreeAccount].balance);
            nextFreeAccount++;
        } else {
            printf("\nAccount with username already exists! Please try again.\n");
        }
    } else {
        printf("\nToo many accounts in system created!\n");
    }
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