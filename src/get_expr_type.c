#include "ashrimp.h"
#include "ashrimp_table.h"

ashrimp_table_t *check_is_func(const char *expr)
{
    bool is_fc = false;
    int table_index = 0;
    ashrimp_table_t *table_ptr = ashrimp_table;

    for (; table_index <= (TABLE_SIZE - 1) && !is_fc; table_index++) {
        if ((is_fc = my_strcmp(expr, table_ptr[table_index].ashrimp_name)))
            break;
    }
    if (is_fc)
        return (&(table_ptr[table_index]));
    return (NULL);
}

bool check_valid_reg(const char *expr)
{
    int val = 0;
    int count = 0;
    int arr_index = 0;
    char *i_arr = NULL;

    for (int index = 1; expr[index]; index++, count++) {
        if (!(check_is_nb(expr[index]))) {
            fprintf(stderr, "Incorrect value for register [%s] !\n", expr);
            exit(EXIT_FAILURE);
        }
    }
    i_arr = gc_malloc(sizeof(char) * (count + 1));
    my_memset(i_arr, '\0', (count + 1));
    for (int index = 1; expr[index]; index++, arr_index++)
        i_arr[arr_index] = expr[index];
    val = atoi(i_arr);
    if (val < 0 || val > 16) {
        fprintf(stderr, "Incorrect value for register [%s] !\n", expr);
        exit(EXIT_FAILURE);
    }
    return (true);
}

void *get_expr_type(const char *expr)
{
    bool is_nb = true;
    ashrimp_table_t *fc = NULL;

    if (expr[0] == 'r' && check_valid_reg(expr)) {
        return ((void *) ASHRMP_ARGS_REG);
    } else if (check_is_nb(expr[0])) {
        for (int index = 0; expr[index] && is_nb; index++)
            is_nb = check_is_nb(expr[index]);
        if (!is_nb) {
            fprintf(stderr, "Unknown expression [%s] !\n", expr);
            exit(EXIT_FAILURE);
        }
        return ((void *) ASHRMP_ARGS_INT);
    } else if (expr[0] == LABEL_SYMB) {
        return ((void *) ASHRMP_ARGS_LABEL);
    } else if ((fc = check_is_func(expr))) {
        return (fc);
    } else {
        fprintf(stderr, "Unknown expression [%s] !\n", expr);
        exit(EXIT_FAILURE);
    }
}