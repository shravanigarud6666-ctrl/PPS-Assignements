#include <stdio.h>
#include <string.h>
#define SIZE 200

void read_string(char text[], int size) {
    if (fgets(text, size, stdin) != NULL) {
        size_t length = strlen(text);
        if (length > 0 && text[length - 1] == '\n') text[length - 1] = '\0';
        else { int ch; while ((ch = getchar()) != '\n' && ch != EOF) {} }
    } else text[0] = '\0';
}

int main(void) {
    char first[SIZE], second[SIZE], result[2 * SIZE], line[32];
    int choice;
    printf("Enter first string: "); read_string(first, SIZE);
    printf("Enter second string: "); read_string(second, SIZE);
    do {
        printf("\n1. Length\n2. Copy first string\n3. Concatenate\n4. Compare\n5. Search second string in first\n0. Exit\nEnter choice: ");
        if (!fgets(line, sizeof line, stdin) || sscanf(line, "%d", &choice) != 1) {
            printf("Invalid choice.\n"); return 1;
        }
        switch (choice) {
            case 1: printf("Lengths: %zu and %zu\n", strlen(first), strlen(second)); break;
            case 2: strcpy(result, first); printf("Copy: %s\n", result); break;
            case 3: strcpy(result, first); strcat(result, second); printf("Concatenation: %s\n", result); break;
            case 4: {
                int comparison = strcmp(first, second);
                if (comparison == 0) printf("Strings are equal.\n");
                else if (comparison < 0) printf("First string comes before second.\n");
                else printf("First string comes after second.\n");
                break;
            }
            case 5: {
                char *match = strstr(first, second);
                if (match) printf("Found at position %ld (starting from 1).\n", (long)(match - first) + 1);
                else printf("Not found.\n");
                break;
            }
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
