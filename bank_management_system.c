#include <stdio.h>
#include <stdbool.h> 
#include <string.h>

struct BankAccount {
    char username[20];
    char password[20];
    double balance;
};

struct BankAccount accounts[50];
const int maxNoOfAccounts = sizeof(accounts) / sizeof(accounts[0]);
int nextFreeAccount = 0;


bool usernameExists(char* username) {
    for (int i = 0; i < maxNoOfAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return true;
        }
    }

    return false;

}

bool accountExistsUserPass(char* username, char* password) {   
    for (int i = 0; i < maxNoOfAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            return true;
        }
    }

    // implement HashMap for efficiency?

    return false;
    
}

void createAccount() {
    if (nextFreeAccount < maxNoOfAccounts) {
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

void launchLoginMenu(char* username) {
    char userInput;

    printf("\nHello, %s!\n\n", username);

    while (true) {
        printf("Please select an action:\n\n");

        printf("(1) - View balance\n");
        printf("(2) - Deposit cash\n");
        printf("(3) - Withdraw cash\n");
        printf("(4) - Transfer funds to another user\n");
        printf("(X) - Return to home screen\n\n");

        scanf(" %c", &userInput);

        switch(userInput) {
        case '1' :
            // view balance
        case '2' :
            // deposit
        case '3' :
            // withdraw
        case '4' :
            // transfer
        case 'X':
            printf("Returning to main menu!\n");
            return;
        default :
            printf("Invalid input!\n\n");

        }
    }    
}

void login() {
    char enteredUsername[20];
    char enteredPassword[20];

    printf("\nEnter username:\n");
    scanf("%s", enteredUsername);
    printf("\nEnter password\n");
    scanf("%s", enteredPassword);

    if (accountExistsUserPass(enteredUsername, enteredPassword)) {
        launchLoginMenu(enteredUsername);
    } else {
        printf("\nSorry, account does not exist!\n");
    }
}

int main() {
    bool keepRunning = true;
    char userInput;

    printf("Welcome to Bhayani Banking!\n");

    while (true) {
        printf("\nPlease select an action:\n\n");

        printf("(1) - Create account\n");
        printf("(2) - Login\n");
        printf("(X) - Exit\n\n");

        scanf(" %c", &userInput);
        
        switch(userInput) {
        case '1' :
            createAccount();
            break;
        case '2' :
            login();
            break;
        case 'X' :
            printf("Thank you for banking with us!\n");
            return 0;
        default :
            printf("Invalid input!\n");
            break;

        }

    }

}