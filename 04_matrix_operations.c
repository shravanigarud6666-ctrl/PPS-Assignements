#include <stdio.h>
#define MAX 10

int main(void) {
    int rows, cols, a[MAX][MAX], b[MAX][MAX];
    printf("Enter number of rows and columns (1-%d): ", MAX);
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        printf("Invalid dimensions.\n"); return 1;
    }
    printf("Enter first matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (scanf("%d", &a[i][j]) != 1) { printf("Invalid input.\n"); return 1; }
    printf("Enter second matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (scanf("%d", &b[i][j]) != 1) { printf("Invalid input.\n"); return 1; }
    printf("Addition of two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%lld\t", (long long)a[i][j] + b[i][j]);
        printf("\n");
    }
    printf("Subtraction of two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%lld\t", (long long)a[i][j] - b[i][j]);
        printf("\n");
    }
    return 0;
}
