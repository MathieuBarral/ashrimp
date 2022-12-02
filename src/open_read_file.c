#include "ashrimp.h"

void open_read_file(ashrimp_t *ashrimp)
{
    int in_file_fd = 0;
    struct stat in_file_stat;

    if ((in_file_fd = open(ashrimp->in_filename, O_RDONLY)) == -1) {
        fprintf(stderr, "ERROR: Cannot open file '%s' !\n", ashrimp->in_filename);
        exit(EXIT_FAILURE);
    }
    if (ashrimp->verbose)
        fprintf(stdout, "Opening and reading file '%s' !\n", ashrimp->in_filename);
    fstat(in_file_fd, &in_file_stat);
    ashrimp->infile_process->in_buffer = gc_malloc(sizeof(char) * (in_file_stat.st_size + 1));
    read(in_file_fd, ashrimp->infile_process->in_buffer, in_file_stat.st_size);
}