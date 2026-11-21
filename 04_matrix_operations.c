
#include <stdio.h>

int main()
{
    int A[2][3], B[2][3];
    int i, j;

    printf("Enter elements of first matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nAddition of matrices:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d\t", A[i][j] + B[i][j]);
        }
        printf("\n");
    }

    printf("\nSubtraction of matrices:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d\t", A[i][j] - B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
