#include "utils.h"

char *my_strcat(char *dst, char *src)
{
    int dst_len = my_strlen(dst);
    int src_len = my_strlen(src);
    int buff_index = 0;
    char *buff = gc_malloc(sizeof(char) * (dst_len + src_len) + 1);

    for (int index = 0; index < dst_len; index++, buff_index++)
        buff[buff_index] = dst[index];
    for (int index = 0; index < src_len; index++, buff_index++)
        buff[buff_index] = src[index];
    return (buff);
}