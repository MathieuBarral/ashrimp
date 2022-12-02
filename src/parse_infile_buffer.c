#include "ashrimp.h"

void parse_infile_buffer(ashrimp_t *ashrimp)
{
    char *in_buff = ashrimp->infile_process->in_buffer;
    char **d_buffer = ashrimp->infile_process->double_arr_buffer;
    ashrimp_label_table_t **label_table = &(ashrimp->infile_process->fc_label_table);

    d_buffer = parse_string(in_buff, "\n", false);
    d_buffer = delete_comments(d_buffer);
    // for (int index = 0; d_buffer[index]; index++)
    //     printf("%s\n", d_buffer[index]);
    init_fc_label_table(&ashrimp, d_buffer);
    parse_fc_label_table(label_table);
}