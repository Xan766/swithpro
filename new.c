#include <stdio.h>

#define MAX_CAPACITY 4.0 // Maximum capacity of the dustbin in kg

// ANSI escape codes for colors
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

int main() {
    float currentWeight = 0.0; // Current weight in the dustbin
    float trashWeight;
    int userInput;

    // Ask for the weight of trash the user wants to add
    printf(YELLOW "Enter the weight of the trash you want to put in (in kg): " RESET);
    scanf("%f", &trashWeight);

    // Check if the trash weight exceeds the maximum capacity
    if (currentWeight + trashWeight <= MAX_CAPACITY) {
        printf(GREEN "You can put in %.2f kg of trash.\n" RESET, trashWeight);

        // Ask if the user wishes to add the trash
        printf(YELLOW "Press 1 to confirm adding the trash or 0 to cancel: " RESET);
        scanf("%d", &userInput);

        if (userInput == 1) {
            currentWeight += trashWeight; // Update current weight
            // Calculate the percentage filled
            float percentageFilled = (currentWeight / MAX_CAPACITY) * 100.0;
            printf(GREEN "The dustbin is now %.2f%% filled.\n" RESET, percentageFilled);
        } else {
            printf(RED "You chose not to add the trash.\n" RESET);
        }
    } else {
        float excess = (currentWeight + trashWeight) - MAX_CAPACITY;
        printf(RED "You cannot put in %.2f kg of trash. Please remove %.2f kg to avoid overflow.\n" RESET, 
               trashWeight, excess);
    }

    return 0;
}
