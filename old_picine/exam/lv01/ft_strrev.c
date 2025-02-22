
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char a)
{
    write(1, &a, 1);
}

void rev_print(char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    while (len > 0)
    {
        ft_putchar(str[len - 1]);
        len--;
    }

    ft_putchar('\n');
}



int main(int argc,char **argv)
{
    if(argc != 2)
        ft_putchar('\n');
    else
        rev_print(argv[1]);
}