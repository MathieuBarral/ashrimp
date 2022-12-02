#include "ashrimp.h"
#include "ashrimp_table.h"

bool check_format(char **d_buffer, int len_tmp_index)
{
    char **tmp_error_arr = NULL;

    if (d_buffer[len_tmp_index][0] != '\t' && d_buffer[len_tmp_index][my_strlen(d_buffer[len_tmp_index]) - 1] != FUNCTION_SYMB) {
        fprintf(stderr, "ERROR (line %d): [%s]\nMissing tab space\n", len_tmp_index, d_buffer[len_tmp_index]);
        exit(EXIT_FAILURE);
    }
    if (d_buffer[len_tmp_index][0] == '\t' && d_buffer[len_tmp_index][my_strlen(d_buffer[len_tmp_index]) - 1] == FUNCTION_SYMB) {
        tmp_error_arr = parse_string(d_buffer[len_tmp_index], "\t", false);
        fprintf(stderr, "ERROR (line %d): [%s]\nUnknown instruction\n", len_tmp_index, tmp_error_arr[1]);
        exit(EXIT_FAILURE);
    }
    return (true);
}

char **init_new_label_values(char **d_buffer, int index)
{
    int new_arr_len = 0;
    int tmp_index = index + 1;
    int arr_index = 0;
    char **new_d_arr = NULL;
    char **tmp_buff_arr = NULL;

    for (int len_tmp_index = tmp_index; d_buffer[len_tmp_index] && \
    d_buffer[len_tmp_index][my_strlen(d_buffer[len_tmp_index]) - 1] != FUNCTION_SYMB; \
    len_tmp_index++, new_arr_len++);
    new_d_arr = gc_malloc(sizeof(char *) * (new_arr_len + 1));
    for (; arr_index < (new_arr_len + 1); arr_index++)
        new_d_arr[arr_index] = gc_malloc(sizeof(char) * 20);
    arr_index = 0;
    for (; d_buffer[tmp_index] && \
    check_format(d_buffer, tmp_index) && \
    d_buffer[tmp_index][my_strlen(d_buffer[tmp_index]) - 1] != FUNCTION_SYMB; tmp_index++, arr_index++) {
        tmp_buff_arr = parse_string(d_buffer[tmp_index], "\t", false);
        new_d_arr[arr_index] = my_strcpy(tmp_buff_arr[1]);
    }
    new_d_arr[arr_index] = NULL;
    return (new_d_arr);
}

void add_label_in_list(ashrimp_label_table_t **label_table, char **d_buffer, int index)
{
    ashrimp_label_table_t *tmp = *label_table;
    ashrimp_label_table_t *new_label = gc_malloc(sizeof(ashrimp_label_table_t));
    char sep[2] = {FUNCTION_SYMB, 0};
    char **label_arr = parse_string(d_buffer[index], sep, false);

    check_name_format(label_arr[0], "function");
    new_label->label_str = my_strcpy(label_arr[0]);
    new_label->label_addr = 0;
    new_label->label_value = init_new_label_values(d_buffer, index);
    new_label->next = NULL;
    if (!(*label_table)) {
        (*label_table) = new_label;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new_label;
}

void init_fc_label_table(ashrimp_t **ashrimp, char **d_buffer)
{
    bool is_main = false;
    ashrimp_label_table_t **label_table =  &((*ashrimp)->infile_process->fc_label_table);

    for (int index = 0; d_buffer[index]; index++) {
        if (d_buffer[index][my_strlen(d_buffer[index]) - 1] == FUNCTION_SYMB)
            add_label_in_list(label_table, d_buffer, index);
    }
    for (ashrimp_label_table_t *tmp = (*label_table); tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->label_str, "main"))
            is_main = true;
    }
    if (!is_main) {
        fprintf(stderr, "No main function found !\n");
        exit(EXIT_FAILURE);
    }
    init_label_addr(label_table);
    // for (ashrimp_label_table_t *tmp = (*label_table); tmp; tmp = tmp->next) {
    //     printf("id: %s, addr: %d: \n", tmp->label_str, tmp->label_addr);
    //     for (int index = 0; tmp->label_value[index]; index++)
    //         printf("\t%s\n", tmp->label_value[index]);
    // }
    // printf("--------------------------------------------------\n");
}