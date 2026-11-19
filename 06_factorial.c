#include <stdio.h>

unsigned long long factorial_recursive(int n) {
    if (n <= 1) return 1;
    return (unsigned long long)n * factorial_recursive(n - 1);
}

unsigned long long factorial_iterative(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) result *= (unsigned long long)i;
    return result;
}

int main(void) {
    int n;
    printf("Enter a non-negative integer (0-20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Please enter a number from 0 to 20.\n"); return 1;
    }
    printf("Factorial using recursion = %llu\n", factorial_recursive(n));
    printf("Factorial without recursion = %llu\n", factorial_iterative(n));
    return 0;
}
