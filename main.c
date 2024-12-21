#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

void print_usage() {
    printf("Usage:\n");
    printf("./sed_simplified input.txt -r 'old_regex' 'new_text'\n");
    printf("./sed_simplified input.txt -d 'regex'\n");
    printf("./sed_simplified input.txt -i 'text_to_add_start'\n");
    printf("./sed_simplified input.txt -b 'text_to_add_end'\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    const char *file_path = argv[1];
    const char *option = argv[2];

    if (strcmp(option, "-r") == 0 && argc == 5) {
        replace_text_regex(file_path, argv[3], argv[4]);
    } else if (strcmp(option, "-d") == 0 && argc == 4) {
        delete_lines_regex(file_path, argv[3]);
    } else if (strcmp(option, "-i") == 0 && argc == 4) {
        add_text_start(file_path, argv[3]);
    } else if (strcmp(option, "-b") == 0 && argc == 4) {
        add_text_end(file_path, argv[3]);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}
