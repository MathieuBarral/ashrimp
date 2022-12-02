#include "ashrimp.h"

void set_output_file(const char *out_filename, ashrimp_t *ashrimp)
{
    if (!out_filename || out_filename[0] == '-') {
        fprintf(stderr, "Missing parameter for output argument !\n");
        exit(EXIT_FAILURE);
    }
    check_file_ext(out_filename, OUTFILE_EXT);
    check_filename(out_filename, OUTFILE_EXT);
    ashrimp->out_filename = my_strcpy(out_filename);
    if (ashrimp->verbose)
        printf("Set output file to '%s' !\n", out_filename);
}