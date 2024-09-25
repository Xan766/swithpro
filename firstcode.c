#include <stdio.h>

// ANSI escape codes for colors
#define PINK "\033[35m"   // Magenta/Pink color
#define RESET "\033[0m"   // Reset to default color

// Function to change bulb color
void changeColor(char color) {
    switch (color) {
        case 'R':
        case 'r':
            printf("The bulb color is RED.\n");
            break;
        case 'B':
        case 'b':
            printf("The bulb color is BLUE.\n");
            break;
        case 'G':
        case 'g':
            printf("The bulb color is GREEN.\n");
            break;
        default:
            printf(PINK "Error: Invalid color input! Please enter R, B, or G.\n" RESET);
    }
}

int main() {
    int switchState;
    char colorInput;

    // Prompt the user for the switch state
    printf("Do you want to turn ON or OFF the bulb? (0 for OFF, 1 for ON): ");
    scanf("%d", &switchState);

    // Check the input for switch state
    if (switchState == 0) {
        printf("The switch is OFF. The bulb is not lit.\n");
    } else if (switchState == 1) {
        printf("The switch is ON.\n");

        // Present color options to the user
        printf("You can change the color by pressing:\n");
        printf("R for Red\n");
        printf("B for Blue\n");
        printf("G for Green\n");
        printf("Enter the desired bulb color (R, B, G): ");
        scanf(" %c", &colorInput); // Note the space before %c to consume any whitespace

        // Change the bulb color
        changeColor(colorInput);
    } else {
        printf(PINK "Error: Invalid input! Please enter 0 or 1.\n" RESET);
        return 1; // Exit the program on invalid input
    }

    return 0;
}