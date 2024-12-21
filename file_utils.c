#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(length + 1);
    fread(content, 1, length, file);
    content[length] = '\0';

    fclose(file);
    return content;
}

void write_file(const char *file_path, const char *content) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fwrite(content, 1, strlen(content), file);
    fclose(file);
}
