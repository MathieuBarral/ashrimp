#ifndef ASHRIMP_H
    #define ASHRIMP_H

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #include "utils.h"
    #include "parser.h"
    #include "gc.h"

    #define INFILE_EXT "ash"
    #define OUTFILE_EXT "ashrimp"
    #define MAGIC_ID "ASHRMP"

    // Output file header structure
    typedef struct ashrimp_fileout_s
    {
        char magic_id[16];
        u_int32_t version_nb;
        u_int32_t code_size;
        u_int32_t code_entry;
        char *code_data;
    } ashrimp_fileout_t;

    // Label list template structure
    typedef struct ashrimp_label_table_s
    {
        char *label_str;
        u_int32_t label_addr;
        char **label_value;
        struct ashrimp_label_table_s *next;
    } ashrimp_label_table_t;

    // Input file processing struture
    typedef struct ashrimp_process_s
    {
        char *in_buffer;
        char **double_arr_buffer;
        ashrimp_label_table_t *fc_label_table;
    } ashrimp_process_t;

    // General structure
    typedef struct ashrimp_s
    {
        char *in_filename;
        char *out_filename;
        bool verbose;
        ashrimp_process_t *infile_process;
        ashrimp_fileout_t *outfile_format;
    } ashrimp_t;

    /**
     * @brief Handle user input error
     *
     * @param argc Program arguments number
     * @param argv Program arguments list
     * @param ashrimp General structure pointer
     */
    void input_error_handler(int argc, char **argv, ashrimp_t *ashrimp);

    /**
     * @brief Set output file name
     *
     * @param out_filename Output file name
     * @param ashrimp General structure pointer
     */
    void set_output_file(const char *out_filename, ashrimp_t *ashrimp);

    /**
     * @brief Open and read input file
     *
     * @param ashrimp General structure pointer
     */
    void open_read_file(ashrimp_t *ashrimp);

    /**
     * @brief Delete comment in input file
     *
     * @param d_buffer Pointer of input file buffer
     *
     * @return Double pointer of infile buffer without comments
     */
    char **delete_comments(char **d_buffer);

    /**
     * @brief Parse input file buffer
     *
     * @param ashrimp General structure pointer
     */
    void parse_infile_buffer(ashrimp_t *ashrimp);

    /**
     * @brief Create and initialize label table
     *
     * @param ashrimp General structure double pointer
     * @param d_buffer Pointer of input file buffer
     */
    void init_fc_label_table(ashrimp_t **ashrimp, char **d_buffer);

    /**
     * @brief Initialize label address
     *
     * @param label_table Label table structure double pointer
     */
    void init_label_addr(ashrimp_label_table_t **label_table);

    /**
     * @brief Parse label table
     *
     * @param label_table Label table structure double pointer
     */
    void parse_fc_label_table(ashrimp_label_table_t **label_table);

    /**
     * @brief Get the expression type
     *
     * @param expr Expression string
     *
     * @return Expression type cast to void pointer
     */
    void *get_expr_type(const char *expr);

    /**
     * @brief Print help page
     */
    void print_help(void);

#endif