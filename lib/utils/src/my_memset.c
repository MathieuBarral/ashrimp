void my_memset(void *dst, char filler, int size)
{
    char *tmp_dst = (char *) dst;

    for (int index = 0; index < size; index++)
        tmp_dst[index] = filler;
}