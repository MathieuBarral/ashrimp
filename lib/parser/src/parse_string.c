#include "parser.h"
#include "utils.h"
#include "gc.h"

int check_is_curr_and_next_sep(const char c_curr, const char c_next, const char *sep, int *str_index, bool include_sep)
{
    bool is_curr_sep = false;
    bool is_next_sep = false;

    for (int sep_index = 0; sep[sep_index]; sep_index++) {
        if (c_curr == sep[sep_index])
            is_curr_sep = true;
    }
    if (is_curr_sep && c_next) {
        for (int sep_index = 0; sep[sep_index]; sep_index++) {
            if (c_next == sep[sep_index])
                is_next_sep = true;
        }
    }
    if (is_curr_sep && is_next_sep) {
        (*str_index)++;
        return (1);
    }
    if (is_curr_sep)
        return ((!include_sep) ? 1 : 2);
    return (0);
}

char **create_double_arr(const char *str, const char *sep, bool include_sep)
{
    int index = 0;
    int line_count = 0;
    char **d_arr = NULL;
    bool previous_sep = true;

    for (int str_index = 0; str[str_index]; str_index++)
        line_count += check_is_curr_and_next_sep(str[str_index], str[str_index + 1], sep, &str_index, include_sep);
    d_arr = gc_malloc(sizeof(char *) * (line_count + 1));
    for (; index <= line_count; index++)
        d_arr[index] = gc_malloc(sizeof(char) * 20);
    d_arr[index] = NULL;
    return (d_arr);
}

char **parse_string(const char *str, const char *sep, bool include_sep)
{
    int arr_str_index = 0;
    int arr_char_index = 0;
    char **d_arr = NULL;
    bool valid_char_append = false;
    bool previous_sep = false;

    d_arr = create_double_arr(str, sep, include_sep);
    for (int str_index = 0; str[str_index]; str_index++) {
        valid_char_append = true;
        for (int sep_index = 0; sep[sep_index]; sep_index++) {
            if (str[str_index] == sep[sep_index]) {
                if (!previous_sep) {
                    arr_str_index++;
                    previous_sep = true;
                }
                arr_char_index = 0;
                valid_char_append = false;
                if (include_sep) {
                    d_arr[arr_str_index][arr_char_index] = str[str_index];
                    arr_str_index++;
                }
            }
        }
        if (valid_char_append) {
            d_arr[arr_str_index][arr_char_index] = str[str_index];
            arr_char_index++;
            previous_sep = false;
        }
    }
    if (my_strcmp(d_arr[arr_str_index], ""))
        d_arr[arr_str_index] = NULL;
    return (d_arr);
}