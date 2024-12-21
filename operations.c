#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "file_utils.h"

void replace_text_regex(const char *file_path, const char *regex_pattern, const char *new_text) {
    char *content = read_file(file_path);
    if (!content) return;

    regex_t regex;
    regcomp(&regex, regex_pattern, REG_EXTENDED);

    char *result = malloc(strlen(content) + 1);
    result[0] = '\0';

    char *line = strtok(content, "\n");
    while (line) {
        regmatch_t match;
        if (regexec(&regex, line, 1, &match, 0) == 0) {
            char *prefix = strndup(line, match.rm_so);
            char *suffix = strdup(line + match.rm_eo);

            strcat(result, prefix);
            strcat(result, new_text);
            strcat(result, suffix);
            strcat(result, "\n");

            free(prefix);
            free(suffix);
        } else {
            strcat(result, line);
            strcat(result, "\n");
        }
        line = strtok(NULL, "\n");
    }

    regfree(&regex);
    write_file(file_path, result);
    free(result);
}

void delete_lines_regex(const char *file_path, const char *regex_pattern) {
    char *content = read_file(file_path);
    if (!content) return;

    regex_t regex;
    regcomp(&regex, regex_pattern, REG_EXTENDED);

    char *result = malloc(strlen(content) + 1);
    result[0] = '\0';

    char *line = strtok(content, "\n");
    while (line) {
        if (regexec(&regex, line, 0, NULL, 0) != 0) {
            strcat(result, line);
            strcat(result, "\n");
        }
        line = strtok(NULL, "\n");
    }

    regfree(&regex);
    write_file(file_path, result);
    free(result);
}

void add_text_start(const char *file_path, const char *text) {
    char *content = read_file(file_path);
    if (!content) return;

    char *result = malloc(strlen(content) + strlen(text) * 2 + 1);
    result[0] = '\0';

    char *line = strtok(content, "\n");
    while (line) {
        strcat(result, text);
        strcat(result, line);
        strcat(result, "\n");
        line = strtok(NULL, "\n");
    }

    write_file(file_path, result);
    free(result);
}

void add_text_end(const char *file_path, const char *text) {
    char *content = read_file(file_path);
    if (!content) return;

    char *result = malloc(strlen(content) + strlen(text) * 2 + 1);
    result[0] = '\0';

    char *line = strtok(content, "\n");
    while (line) {
        strcat(result, line);
        strcat(result, text);
        strcat(result, "\n");
        line = strtok(NULL, "\n");
    }

    write_file(file_path, result);
    free(result);
}
