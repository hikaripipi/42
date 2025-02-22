#include <unistd.h>

void putchar(char a)
{
    write(1, &a, 1);
}

void putstr(char *str)
{
    int i;
    i = 0;

    while(str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }

}

int main(int argc, char **argv)
{
    if (argc < 2)
        putchar('\n');
    else
    {
        putstr(argv[1]);
        putchar('\n');
    }
    return 0;
}