int my_strlen(const char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}