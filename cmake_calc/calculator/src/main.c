#include <stdio.h>
#include "calc.h"

int main() {
    int a, b, choice;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("\nCalculator Menu\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Result = %d\n", add(a, b));
            break;
        case 2:
            printf("Result = %d\n", sub(a, b));
            break;
        case 3:
            printf("Result = %d\n", mul(a, b));
            break;
        case 4:
            printf("Result = %d\n", divide(a, b));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
