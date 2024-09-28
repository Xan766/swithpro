#include <stdio.h>

// ANSI escape codes for colors
#define PINK "\033[35m"   // Magenta/Pink color
#define RESET "\033[0m"   // Reset to default color

int main() {
    int switchState;

    // Prompt the user for the switch state
    printf("Do you want to turn ON or OFF the bulb? (0 for OFF, 1 for ON): ");
    scanf("%d", &switchState);

    // Check the input for switch state
    if (switchState == 0) {
        printf("The switch is OFF. The bulb is not lit.\n");
    } else if (switchState == 1) {1

        printf("The switch is ON. The bulb is lit.\n");
    } else {
        printf(PINK "Error: Invalid input! Please enter 0 or 1.\n" RESET);
        return 1; // Exit the program on invalid input
    }

    return 0;
}
