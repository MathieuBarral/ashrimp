#include "ashrimp.h"
#include "ashrimp_table.h"

void search_comment(char *d_buffer, char **new_d_buffer, int *new_index)
{
    char symb[2] = {COMMENT_SYMBOL, '\0'};

    if (d_buffer[0] == COMMENT_SYMBOL)
        return;
    if (strstr(d_buffer, symb) != NULL) {
        for (int index = 0; d_buffer[index] && \
        d_buffer[index] != COMMENT_SYMBOL; index++)
            new_d_buffer[(*new_index)][index] = d_buffer[index];
        (*new_index)++;
    } else {
        new_d_buffer[(*new_index)] = my_strcpy(d_buffer);
        (*new_index)++;
    }
}

char **delete_comments(char **d_buffer)
{
    int arr_len = 0;
    int new_index = 0;
    char **new_d_buffer = NULL;

    for (int index = 0; d_buffer[index]; index++)
        arr_len += (d_buffer[index][0] != COMMENT_SYMBOL) ? 1 : 0;
    new_d_buffer = gc_malloc(sizeof(char *) * arr_len);
    for (int index = 0; index < arr_len; index++) {
        new_d_buffer[index] = gc_malloc(sizeof(char) * 20);
        my_memset(new_d_buffer[index], '\0', 20);
    }
    new_d_buffer[arr_len] = NULL;
    for (int index = 0; d_buffer[index]; index++)
        search_comment(d_buffer[index], new_d_buffer, &new_index);
    gc_free(d_buffer);
    return (new_d_buffer);
}