#include <stdio.h>

int main() {
    int userInput;

    // Prompt the user for confirmation
    printf("Do you want to confirm the transaction?\n");
    printf("Press 1 for Yes, 0 for No: ");
    scanf("%d", &userInput);

    // Check user input and respond accordingly
    if (userInput == 1) {
        printf("Transaction is done.\n");
    } else if (userInput == 0) {
        printf("Transaction failed.\n");
    } else {
        printf("Invalid input. Please enter 1 for Yes or 0 for No.\n");
    }

    return 0;
}
