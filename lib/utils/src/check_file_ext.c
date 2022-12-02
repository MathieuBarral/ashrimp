#include "utils.h"

void check_file_ext(const char *filename, const char *file_ext)
{
    int index = 0;
    int ext_len = 0;
    char *ext_buff = NULL;

    for (; filename[index] && filename[index] != '.'; index++);
    if (!(filename[index] == '.')) {
        fprintf(stderr, "File argument format must be <filename>.%s\n", file_ext);
        exit(EXIT_FAILURE);
    }
    index++;
    for (int tmp_index = index; filename[tmp_index]; tmp_index++, ext_len++);
    ext_buff = gc_malloc(sizeof(char) * (ext_len + 1));
    for (int buff_index = 0; filename[index]; index++, buff_index++)
        ext_buff[buff_index] = filename[index];
    if (!my_strcmp(ext_buff, file_ext)) {
        fprintf(stderr, "Invalid file extension '.%s' !\n", ext_buff);
        fprintf(stderr, "Must be a .%s file\n", file_ext);
        exit(EXIT_FAILURE);
    }
}