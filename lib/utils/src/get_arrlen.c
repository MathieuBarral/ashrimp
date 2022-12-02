int get_d_arrlen(void *arr)
{
    int len = 0;
    char **tmp_arr = (char **) arr;

    for (; tmp_arr[len]; len++);
    return (len);
}