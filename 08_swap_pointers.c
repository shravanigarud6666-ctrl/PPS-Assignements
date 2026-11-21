
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nBefore Swapping:\n");
    printf("First number = %d, Second number = %d\n",
           num1, num2);

    swap(&num1, &num2);

    printf("\nAfter Swapping:\n");
    printf("First number = %d, Second number = %d\n",
           num1, num2);

    return 0;
}
