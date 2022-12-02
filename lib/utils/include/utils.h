#ifndef UTILS_H
    #define UTILS_H

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #include "gc.h"

    /**
     * @brief Return lenght of given string
     *
     * @param str String to get the length of
     *
     * @return String length
     */
    int my_strlen(const char *str);

    /**
     * @brief Concatenate two string
     *
     * @param dst String to concatenate
     * @param src String to concatenate into
     *
     * @return Concatened string
     */
    char *my_strcat(char *dst, char *src);

    /**
     * @brief Compare two string
     *
     * @param f_cmp First string to compare
     * @param s_cmp Second string to compare
     *
     * @return True if the string are equals, False otherwise
     */
    bool my_strcmp(const char *f_cmp, const char *s_cmp);

    /**
     * @brief Fill the content of given memory zone with given character
     *
     * @param dst Pointer to desired memory zone to fill
     * @param filler Character to fill memory zone witf
     * @param size Size of memory zone to fill
     */
    void my_memset(void *dst, char filler, int size);

    /**
     * @brief Return a copy of given string
     *
     * @param src String to copy
     *
     * @return Copy of the given string
     */
    char *my_strcpy(const char *src);

    /**
     * @brief Check given filename extension for error handling
     *
     * @param filename Filename to check extention of
     * @param file_ext Extention to check
     */
    void check_file_ext(const char *filename, const char *file_ext);

    /**
     * @brief Check given filename for error handling
     *
     * @param filename Filename to check
     * @param file_ext File extention
     */
    void check_filename(const char *filename, char *file_ext);

    /**
     * @brief Check given name format
     *
     * @param str Name to check
     * @param type Type of name
     */
    void check_name_format(const char *str, const char *type);

    /**
     * @brief Get length of given double array
     *
     * @param arr Double array to get length of
     *
     * @return Length of double array
     */
    int get_d_arrlen(void *arr);

    /**
     * @brief Check if given character is a number
     *
     * @param c Character to check
     *
     * @return True if given character is a number, False otherwise
     */
    bool check_is_nb(char c);

#endif