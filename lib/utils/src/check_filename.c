#include "utils.h"

void check_filename(const char *filename, char *file_ext)
{
    int name_len = 0;
    char *name_buff = NULL;

    if (filename[0] == '.') {
        fprintf(stderr, "File argument format must be <filename>.%s\n", file_ext);
        exit(EXIT_FAILURE);
    }
    for (; filename[name_len] && filename[name_len] != '.'; name_len++);
    name_buff = gc_malloc(sizeof(char) * (name_len + 1));
    for (int index = 0; index < name_len; index++)
        name_buff[index] = filename[index];
    check_name_format(name_buff, "file");
}