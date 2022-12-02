#include "utils.h"

char *my_strcpy(const char *src)
{
    int len = my_strlen(src);
    char *out_str = gc_malloc(sizeof(char) * (len + 1));

    for (int index = 0; index < len; index++)
        out_str[index] = src[index];
    return (out_str);
}