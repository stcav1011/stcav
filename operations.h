#ifndef OPERATIONS_H
#define OPERATIONS_H

void replace_text_regex(const char *file_path, const char *regex_pattern, const char *new_text);
void delete_lines_regex(const char *file_path, const char *regex_pattern);
void add_text_start(const char *file_path, const char *text);
void add_text_end(const char *file_path, const char *text);

#endif
