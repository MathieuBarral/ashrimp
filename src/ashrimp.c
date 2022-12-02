#include "ashrimp.h"
#include "ashrimp_table.h"

int main(int argc, char **argv)
{
    ashrimp_t ashrimp = {0};
    ashrimp.infile_process = gc_malloc(sizeof(ashrimp_process_t));
    ashrimp.outfile_format = gc_malloc(sizeof(ashrimp_fileout_t));

    input_error_handler(argc, argv, &ashrimp);
    open_read_file(&ashrimp);
    parse_infile_buffer(&ashrimp);
    return (0);
}