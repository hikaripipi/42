#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void find_a(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == 'a')
        {
            ft_putchar('a');
            return;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        ft_putchar('a');
    }
    else
    {
        find_a(argv[1]);
    }
    ft_putchar('\n');
}