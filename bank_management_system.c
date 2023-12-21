#include <stdio.h>
#include <stdbool.h> 

int main() {
    bool keepRunning = true;
    char mainScreenInput;

    printf("Welcome to Bhayani Banking!\n");

    while (keepRunning) {
        printf("\nPlease select an action: \n");

        printf("(1) - Create account\n");
        printf("(2) - Login\n");
        printf("(X) - Exit\n");
        scanf(" %c", &mainScreenInput);
        
        switch(mainScreenInput) {
        case '1' :
            printf("Creating account!\n");
            break;
        case '2' :
            printf("Logging in!\n");
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
