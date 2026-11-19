#include <stdio.h>
#include <string.h>

int main(void) {
    char source_name[256], destination_name[256];
    FILE *source, *destination;
    int ch;
    printf("Enter source file path: ");
    if (!fgets(source_name, sizeof source_name, stdin) || !strchr(source_name, '\n')) { printf("Invalid or too long path.\n"); return 1; }
    source_name[strcspn(source_name, "\n")] = '\0';
    printf("Enter destination file path: ");
    if (!fgets(destination_name, sizeof destination_name, stdin) || !strchr(destination_name, '\n')) { printf("Invalid or too long path.\n"); return 1; }
    destination_name[strcspn(destination_name, "\n")] = '\0';
    source = fopen(source_name, "rb");
    if (!source) { perror("Cannot open source file"); return 1; }
    /* Exclusive creation avoids overwriting an existing file, including the source. */
    destination = fopen(destination_name, "wbx");
    if (!destination) { perror("Cannot create destination (it may already exist)"); fclose(source); return 1; }
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, destination) == EOF) { perror("Write error"); fclose(source); fclose(destination); return 1; }
    }
    if (ferror(source)) { perror("Read error"); fclose(source); fclose(destination); return 1; }
    if (fclose(source) != 0) { perror("Error closing source"); fclose(destination); return 1; }
    if (fclose(destination) != 0) { perror("Error closing destination"); return 1; }
    printf("File copied successfully.\n");
    return 0;
}
