
#include <stdio.h>

int main()
{
    FILE *source, *target;
    char ch;
    char file1[100], file2[100];

    printf("Enter source file name: ");
    scanf("%99s", file1);

    printf("Enter destination file name: ");
    scanf("%99s", file2);

    source = fopen(file1, "r");

    if(source == NULL)
    {
        printf("Cannot open source file");
        return 1;
    }

    target = fopen(file2, "w");

    if(target == NULL)
    {
        printf("Cannot create destination file");
        fclose(source);
        return 1;
    }

    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch, target);
    }

    printf("File copied successfully!");

    fclose(source);
    fclose(target);

    return 0;
}
