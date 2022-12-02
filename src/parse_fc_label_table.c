#include "ashrimp.h"
#include "ashrimp_table.h"

void check_expr_type(const char *expr, ashrimp_label_table_t *label_table, int *args_nb, unsigned int *op_arr)
{
    static int op_arr_index = 0;
    static int fc_args_nb = 0;
    ashrimp_table_t *fc = NULL;
    char **tmp_label_arr = NULL;
    char sep[2] = {LABEL_SYMB, 0};

    if ((*args_nb) > fc_args_nb) {
        fprintf(stderr, "Too many args [%s] !\n", expr);
        exit(EXIT_FAILURE);
    }
    if (get_expr_type(expr) == (void *) ASHRMP_ARGS_REG) {
        printf("%s -> REG -> op: 0x%x\n", expr, ASHRMP_ARGS_REG);
        op_arr[op_arr_index] = (u_int32_t) ASHRMP_ARGS_REG;
        op_arr[++op_arr_index] = (u_int32_t) 0x000000ff;
    } else if (get_expr_type(expr) == (void *) ASHRMP_ARGS_INT) {
        printf("%s -> INT -> op: 0x%x\n", expr, ASHRMP_ARGS_INT);
        op_arr[op_arr_index] = (u_int32_t) ASHRMP_ARGS_INT;
        op_arr[++op_arr_index] = (u_int32_t) atoi(expr);
    } else if (get_expr_type(expr) == (void *) ASHRMP_ARGS_LABEL) {
        tmp_label_arr = parse_string(expr, sep, false);
        for (; label_table && !my_strcmp(label_table->label_str, tmp_label_arr[1]); label_table = label_table->next);
        printf("LABEL -> %s -> op: 0x%x -> addr: %d\n", label_table->label_str, ASHRMP_ARGS_LABEL, label_table->label_addr);
        op_arr[op_arr_index] = (u_int32_t) ASHRMP_ARGS_LABEL;
        op_arr[++op_arr_index] = label_table->label_addr;
    } else if ((fc = (ashrimp_table_t *) get_expr_type(expr))) {
        printf("fc: %s, op: 0x%x, args_nb: %d\n", fc->ashrimp_name, fc->type, fc->args_nb);
        op_arr[op_arr_index] = (u_int32_t) fc->type;
        fc_args_nb = fc->args_nb;
    } else {
        fprintf(stderr, "Unknown expression [%s] !\n", expr);
        exit(EXIT_FAILURE);
    }
    op_arr_index++;
    (*args_nb)++;
}

void parse_expression(const char *expr, ashrimp_label_table_t *label_table, unsigned int *op_arr)
{
    int args_nb = 0;
    char sep[3] = {ARGS_SEPARATOR_SYMBOL, ' ', 0};
    char **tmp_expr_arr = parse_string(expr, sep, false);

    // printf("expr: %s\n", expr);
    // for (int index = 0; tmp_expr_arr[index]; index++)
    //     printf("args: %s\n", tmp_expr_arr[index]);
    // printf("--------------------------------\n");

    for (int index = 0; tmp_expr_arr[index]; index++)
        check_expr_type(tmp_expr_arr[index], label_table, &args_nb, op_arr);
}

void parse_fc_label_table(ashrimp_label_table_t **label_table)
{
    u_int32_t op_arr[35] = {0};

    for (ashrimp_label_table_t *tmp = (*label_table); tmp; tmp = tmp->next) {
        for (int index = 0; tmp->label_value[index]; index++)
            parse_expression(tmp->label_value[index], (*label_table), op_arr);
    }
    printf("--------------------------------\n");
    for (int index = 0; index < 35; index++)
        printf("%08x\n", op_arr[index]);
    // printf("--------------------------------------------------\n");
    // for (ashrimp_label_table_t *tmp = (*label_table); tmp; tmp = tmp->next) {
    //     printf("id: %s, addr: %d: \n", tmp->label_str, tmp->label_addr);
    //     for (int index = 0; tmp->label_value[index]; index++)
    //         printf("\t%s\n", tmp->label_value[index]);
    // }
}