#include "utils.h"

bool my_strcmp(const char *f_cmp, const char *s_cmp)
{
    for (int index = 0; f_cmp[index] == s_cmp[index]; index++) {
        if (f_cmp[index] == '\0' && s_cmp[index] == '\0')
            return (true);
    }
    return (false);
}