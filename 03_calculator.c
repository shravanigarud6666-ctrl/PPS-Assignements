#include <stdio.h>

int main(void) {
    int choice;
    double a, b;
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nEnter choice: ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("Invalid choice.\n");
        return 1;
    }
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    switch (choice) {
        case 1: printf("Addition = %g\n", a + b); break;
        case 2: printf("Subtraction = %g\n", a - b); break;
        case 3: printf("Multiplication = %g\n", a * b); break;
        case 4:
            if (b == 0) { printf("Cannot divide by zero.\n"); return 1; }
            printf("Division = %g\n", a / b);
            break;
    }
    return 0;
}
