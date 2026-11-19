#include <stdio.h>

void swap(int *first, int *second) {
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

int main(void) {
    int first, second;
    printf("Enter the first number: ");
    if (scanf("%d", &first) != 1) return 1;
    printf("Enter the second number: ");
    if (scanf("%d", &second) != 1) return 1;
    printf("Before swapping: First number = %d, Second number = %d\n", first, second);
    swap(&first, &second);
    printf("After swapping: First number = %d, Second number = %d\n", first, second);
    return 0;
}
