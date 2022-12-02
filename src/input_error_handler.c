#include "ashrimp.h"

void args_func(char id, char **argv, int argv_index, ashrimp_t *ashrimp)
{
    switch (id) {
        case 'h': print_help(); break;
        case 'o': set_output_file(argv[argv_index + 1], ashrimp); break;
        case 'v': ashrimp->verbose = true; break;
        default: break;
    }
}

void check_args(char id, char *args_id_list, char **argv, int argv_index, ashrimp_t *ashrimp)
{
    bool is_valid = false;
    int list_len = my_strlen(args_id_list);

    for (int index = 0; index < list_len; index++) {
        if (args_id_list[index] == id)
            is_valid = true;
    }
    if (!is_valid) {
        fprintf(stderr, "Invalid argument '-%c' !\nUse -h to show help page\n", id);
        exit(EXIT_FAILURE);
    } else
        args_func(id, argv, argv_index, ashrimp);
}

void check_infile_format(const char *in_filename, ashrimp_t *ashrimp)
{
    int in_last_pos = 0;
    char **in_filename_arr = NULL;
    char **out_filename_arr = NULL;

    if (!in_filename) {
        fprintf(stderr, "Missing parameter input file argument !\n");
        exit(EXIT_FAILURE);
    }
    in_filename_arr = parse_string(in_filename, "/", false);
    in_last_pos = get_d_arrlen(in_filename_arr) - 1;
    check_file_ext(in_filename_arr[in_last_pos], INFILE_EXT);
    check_filename(in_filename_arr[in_last_pos], INFILE_EXT);
    if (!ashrimp->out_filename) {
        out_filename_arr = parse_string(in_filename_arr[in_last_pos], ".", false);
        set_output_file(my_strcat(out_filename_arr[0], ".ashrimp"), ashrimp);
    }
    ashrimp->in_filename = my_strcpy(in_filename);
    if (ashrimp->verbose)
        printf("Set input file to '%s' !\n", in_filename_arr[in_last_pos]);
}

void input_error_handler(int argc, char **argv, ashrimp_t *ashrimp)
{
    char args_id_list[] = {'h', 'v', 'o'};

    if (argc == 1) {
        fprintf(stderr, "Usage: ashrimp [-v] [-o <output file>] <ashrmp file>\n");
        exit(EXIT_FAILURE);
    } else {
        for (int index = 1; argv[index]; index++) {
            if (argv[index][0] == '-')
                check_args(argv[index][1], args_id_list, argv, index, ashrimp);
        }
        check_infile_format(argv[argc - 1], ashrimp);
    }
}