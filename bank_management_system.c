#include <stdio.h>
#include <stdbool.h> 
#include <string.h>

struct BankAccount {
    char username[20];
    char password[20];
    float balance;
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

double getBalance(char* username) {
    for (int i = 0; i < maxNoOfAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return accounts[i].balance;
        }
    }
    printf("Account not found!\n\n");
    return -99999;
}

bool addBalance(char* username, double amount) {
    // checks if there's issues w amounts
    if (amount < 0) {
        printf("Cannot deposit a negative amount!\n\n");
        return false;
    }

    for (int i = 0; i < maxNoOfAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            accounts[i].balance += amount;
            return true;
        }
    }

    printf("Account %s not found!\n\n", username);
    return false;
}

bool subtractBalance(char* username, double amount) {
    // checks if there's issues w amounts
    if (amount < 0) {
        printf("Cannot withdraw a negative amount!\n\n");
        return false;
    }

    if (amount > getBalance(username)) {
        printf("You do not have enough money to withdraw $%lf!\n\n", amount);
        return false;
    }

    for (int i = 0; i < maxNoOfAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            accounts[i].balance -= amount;
            return true;
        }
    }

    printf("Account %s not found!\n\n", username);
    return false;
}

bool transferMoney(char* usernameGiving, char* usernameReceiving, double amount) {
    // checks if there's issues w usernames given
    if (!usernameExists(usernameGiving) && !usernameExists(usernameReceiving)) {
        printf("Giver %s's and receiver %s's accounts both do not exist!\n\n", usernameGiving, usernameReceiving);
        return false;
    } 

    if (!usernameExists(usernameGiving)) {
        printf("Giver %s's account does not exist!\n\n", usernameGiving);
        return false;
    } 

    if (!usernameExists(usernameReceiving)) {
        printf("Receiver %s's account does not exist!\n\n", usernameReceiving);
        return false;
    }    


    // checks if there's issues w amounts
    if (amount < 0) {
        printf("Cannot transfer a negative amount!\n\n");
        return false;
    }

    if (amount > getBalance(usernameGiving)) {
        printf("%s does not have enough funds to transfer %lf!\n\n", usernameGiving, amount);
        return false;
    }


    subtractBalance(usernameGiving, amount);
    addBalance(usernameReceiving, amount);

    return true;
    
}

void executeDeposit(char* username) {
    double amount;
    printf("How much would you like to deposit?\n");
    scanf("%lf", &amount);

    if (addBalance(username, amount)) {
        printf("Deposit successful!\n");
        printf("Your new balance is $%lf!\n\n", getBalance(username));
    } else {
        printf("Deposit failed!\n\n");
    }
}

void executeWithdrawal(char* username) {
    double amount;
    printf("How much would you like to withdraw?\n");
    scanf("%lf", &amount);

    if (subtractBalance(username, amount)) {
        printf("Withdrawal successful!\n");
        printf("Your new balance is $%lf!\n\n", getBalance(username));
    } else {
        printf("Withdrawal failed!\n\n");
    }
}

void executeViewBalance(char* username) {
    if (usernameExists(username)) {
        printf("Balance in account %s is currently $%lf!\n\n", username, getBalance(username));
    } else {
        printf("Account %s does not exist!", username);
    }
}

void executeTransferFunds(char* username) {
    char usernameReceiver[20];
    double amount;

    printf("Hello, %s!\n\n", username);
    printf("Enter the username of who you like to transfer funds to:\n");
    scanf(" %s", usernameReceiver);
    printf("How much would you like to transfer to %s?\n", usernameReceiver);
    scanf(" %lf", &amount);

    if (transferMoney(username, usernameReceiver, amount)) {
        printf("Transaction successful!\n");
        printf("Your new balance is $%lf!\n\n", getBalance(username));
    } else {
        printf("Transaction failed!\n\n");
    }

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
        printf("(X) - Log out and return to home screen\n\n");

        scanf(" %c", &userInput);

        switch(userInput) {
        case '1' :
            executeViewBalance(username);
            break;
        case '2' :
            executeDeposit(username);
            break;
        case '3' :
            executeWithdrawal(username);
            break;
        case '4' :
            executeTransferFunds(username);
            break;
        case 'X':
            printf("Returning to home screen!\n");
            return;
        default :
            printf("Invalid input!\n\n");
            break;

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
            printf("\n\nThank you for banking with us!\n");
            return 0;
        default :
            printf("Invalid input!\n\n");
            break;

        }

    }

}