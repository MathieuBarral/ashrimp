#ifndef PARSER_H
    #define PARSER_H

    #include <stdlib.h>
    #include <stdbool.h>

    /**
     * @brief Parse string using given separator list
     *
     * @param str String to parse
     * @param sep Separator list
     * @param include_sep Include separator in output
     *
     * @return Double pointer of parsed string
     */
    char **parse_string(const char *str, const char *sep, bool include_sep);

#endif