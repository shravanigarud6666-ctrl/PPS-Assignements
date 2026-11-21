
#include <stdio.h>

long long factorial(int n)
{
    long long fact = 1;
    int i;

    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

long long recursive(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n * recursive(n - 1);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 0 || n > 20)
    {
        printf("Enter a number between 0 and 20");
        return 0;
    }

    printf("Factorial without recursion = %lld\n", factorial(n));

    printf("Factorial with recursion = %lld\n", recursive(n));

    return 0;
}
