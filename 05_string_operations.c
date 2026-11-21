
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], result[200];
    int choice;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    do
    {
        printf("\n1. Length");
        printf("\n2. Copy");
        printf("\n3. Concatenation");
        printf("\n4. Comparison");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Length = %lu\n", (unsigned long)strlen(str1));
                break;

            case 2:
                strcpy(result, str1);
                printf("Copied string = %s\n", result);
                break;

            case 3:
                strcpy(result, str1);
                strcat(result, str2);
                printf("Concatenated string = %s\n", result);
                break;

            case 4:
                if(strcmp(str1, str2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}
