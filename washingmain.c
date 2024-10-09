#include <stdio.h>

int main() {
    int machineStatus;
    char washingChoice;
    int clothesTypeChoice;
    char temperatureChoice;
    int specificTemperature, weight;
    int washTime = 0; // Time in minutes
    char notificationChoice;

    // Color codes
    const char* red = "\033[0;31m";    // Red
    const char* yellow = "\033[1;33m"; // Yellow
    const char* green = "\033[0;32m";  // Green
    const char* reset = "\033[0m";     // Reset to default color

    // Step 1: Turn machine on or off
    printf("%sDo you wish to turn the washing machine ON (1) or OFF (0)? %s", yellow, reset);
    scanf("%d", &machineStatus);

    if (machineStatus == 0) {
        printf("%sThe washing machine is OFF. Goodbye!%s\n", red, reset);
        return 0; // Exit the program if the machine is turned off
    }

    // Step 2: Choose the washing operation (wash, dry, or wash and dry)
    printf("\n%sPlease choose the washing operation:%s\n", yellow, reset);
    printf("%sA. Wash only%s\n", green, reset);
    printf("%sB. Dry only%s\n", green, reset);
    printf("%sC. Wash and Dry%s\n", green, reset);
    printf("%sEnter your choice (A, B, C): %s", yellow, reset);
    getchar(); // to consume the newline from previous input
    scanf("%c", &washingChoice); // Read the operation character

    // Step 3: Choose the type of clothes
    printf("\n%sChoose the type of your clothes:%s\n", yellow, reset);
    printf("%s1. Cotton%s\n", green, reset);
    printf("%s2. Wool%s\n", green, reset);
    printf("%s3. Synthetics%s\n", green, reset);
    printf("%s4. Delicates%s\n", green, reset);
    printf("%sEnter your choice (1-4): %s", yellow, reset);
    scanf("%d", &clothesTypeChoice);

    // Step 4: Ask for temperature preference
    printf("\n%sDo you wish to wash the clothes with Lukewarm (L), Normal (N), or Cold (C) temperature water?%s\n", yellow, reset);
    printf("%sEnter your choice (L/N/C): %s", yellow, reset);
    getchar(); // to consume the newline from previous input
    scanf("%c", &temperatureChoice);

    if (temperatureChoice == 'L' || temperatureChoice == 'l') {
        printf("%sYou have selected lukewarm water.%s\n", green, reset);
    } else if (temperatureChoice == 'N' || temperatureChoice == 'n') {
        printf("%sYou have selected normal temperature water.%s\n", green, reset);
    } else if (temperatureChoice == 'C' || temperatureChoice == 'c') {
        printf("%sYou have selected cold water.%s\n", green, reset);
    } else {
        printf("%sInvalid choice! Please restart the program and enter a valid option.%s\n", red, reset);
        return 0; // Exit the program for an invalid temperature choice
    }

    // Step 5: Ask if the user wants to specify a specific temperature
    if (temperatureChoice == 'L' || temperatureChoice == 'l' || temperatureChoice == 'N' || temperatureChoice == 'n') {
        printf("%sWould you like to specify a specific temperature? (Y/N): %s", yellow, reset);
        getchar(); // to consume the newline from previous input
        char specificTempChoice;
        scanf("%c", &specificTempChoice);

        if (specificTempChoice == 'Y' || specificTempChoice == 'y') {
            printf("%sEnter the specific temperature in Celsius: %s", yellow, reset);
            scanf("%d", &specificTemperature);
            printf("%sWashing clothes at %d°C...%s\n", green, specificTemperature, reset);
        } else if (specificTempChoice == 'N' || specificTempChoice == 'n') {
            printf("%sWashing clothes at the default temperature...%s\n", green, reset);
        } else {
            printf("%sInvalid choice! Please restart the program and enter a valid option.%s\n", red, reset);
            return 0; // Exit the program for an invalid choice
        }
    }

    // Step 6: Check the weight of clothes
    printf("\n%sEnter the weight of your clothes in kg: %s", yellow, reset);
    scanf("%d", &weight);

    // Maximum capacity of the washing machine is 5.5 kg
    if (weight > 5) {
        printf("%sThe weight exceeds the maximum capacity (5.5 kg). Please reduce the weight of clothes.%s\n", red, reset);
        return 0; // Exit the program if the weight exceeds 5.5 kg
    } else if (weight <= 2) {
        washTime = 40; // 40 minutes for clothes <= 2 kg
    } else if (weight > 2 && weight <= 4) {
        washTime = 49; // 49 minutes for clothes > 2 kg and <= 4 kg
    } else if (weight > 4 && weight <= 5) {
        washTime = 59; // 59 minutes for clothes > 4 kg and <= 5 kg
    }

    // Step 7: Display the washing instructions and time
    printf("\n%sThe washing machine is now set to:%s\n", yellow, reset);

    // Show operation mode
    printf("%sOperation: %s", green, reset);
    switch (washingChoice) {
        case 'A':
        case 'a':
            printf("Wash only\n");
            break;
        case 'B':
        case 'b':
            printf("Dry only\n");
            break;
        case 'C':
        case 'c':
            printf("Wash and Dry\n");
            break;
        default:
            printf("%sInvalid operation%s\n", red, reset);
            return 0;
    }

    // Show clothes type
    printf("%sClothes type: %s", green, reset);
    switch (clothesTypeChoice) {
        case 1:
            printf("Cotton\n");
            break;
        case 2:
            printf("Wool\n");
            break;
        case 3:
            printf("Synthetics\n");
            break;
        case 4:
            printf("Delicates\n");
            break;
        default:
            printf("%sInvalid clothes type%s\n", red, reset);
            return 0;
    }

    // Show temperature choice
    printf("%sTemperature choice: %s", green, reset);
    if (temperatureChoice == 'L' || temperatureChoice == 'l') {
        printf("Lukewarm\n");
    } else if (temperatureChoice == 'N' || temperatureChoice == 'n') {
        printf("Normal\n");
    } else {
        printf("Cold\n");
    }

    // Show the time it will take
    printf("\n%sThe washing machine will take approximately %d minutes to complete the wash.%s\n", green, washTime, reset);

    printf("\n%sWashing machine is now operating...%s\n", green, reset);

    // Step 8: Ask the user about smartphone notification
    printf("\n%sWould you like to be notified on your smartphone when the washing or drying is completed? (Y/N): %s", yellow, reset);
    getchar(); // to consume the newline from previous input
    scanf("%c", &notificationChoice);

    if (notificationChoice == 'Y' || notificationChoice == 'y') {
        printf("%sYou will be notified on your smartphone when the process is complete.%s\n", green, reset);
    } else if (notificationChoice == 'N' || notificationChoice == 'n') {
        printf("%sYou will not be notified.%s\n", green, reset);
    } else {
        printf("%sInvalid choice! Please restart the program and enter a valid option.%s\n", red, reset);
        return 0; // Exit the program for an invalid notification choice
    }

    return 0;
}
