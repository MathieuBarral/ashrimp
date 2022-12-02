#include "ashrimp.h"

void check_name_format(const char *str, const char *type)
{
    for (int index = 0; str[index]; index++) {
        if (!((str[index] >= 65 && str[index] <= 90) || (str[index] >= 97 && str[index] <= 122))) {
            fprintf(stderr, "Invalid %s name '%s' !\n", type, str);
            fprintf(stderr, "Name must be composed of only up and low alphabet characters\n");
            exit(EXIT_FAILURE);
        }
    }
}