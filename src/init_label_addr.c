#include "ashrimp.h"
#include "ashrimp_table.h"

u_int16_t get_label_addr(const char *expr)
{
    u_int16_t addr_offset = 0;
    ashrimp_table_t *fc = NULL;
    void *type = get_expr_type(expr);

    if (type != (void *) ASHRMP_ARGS_REG && type != (void *) ASHRMP_ARGS_INT && \
    type != (void *) ASHRMP_ARGS_LABEL) {
        fc = (ashrimp_table_t *) type;
        addr_offset = fc->fc_size;
    }
    return (addr_offset);
}

u_int16_t parse_label_expression(const char *expr)
{
    u_int16_t addr_offset = 0;
    int args_nb = 0;
    char sep[3] = {ARGS_SEPARATOR_SYMBOL, ' ', 0};
    char **tmp_expr_arr = parse_string(expr, sep, false);

    // printf("expr: %s\n", expr);
    // for (int index = 0; tmp_expr_arr[index]; index++)
    //     printf("args: %s\n", tmp_expr_arr[index]);
    // printf("--------------------------------\n");

    for (int index = 0; tmp_expr_arr[index]; index++)
        addr_offset += get_label_addr(tmp_expr_arr[index]);
    return (addr_offset);
}

void init_label_addr(ashrimp_label_table_t **label_table)
{
    u_int32_t new_addrs = 0;

    for (ashrimp_label_table_t *tmp = (*label_table); tmp; tmp = tmp->next) {
        tmp->label_addr = new_addrs;
        for (int index = 0; tmp->label_value[index]; index++)
            new_addrs += parse_label_expression(tmp->label_value[index]);
    }
}