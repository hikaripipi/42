#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_strlen(char *str)
{
    int i;
    i = 0;

    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

void ft_search(char *str, char a, char b)
{
    int i;
    i = 0;

    while(str[i] != '\0')
    {
        
        if(str[i] == a)
        {
            ft_putchar(b);
        }
        else
            ft_putchar(str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;
    i = 0;
    if(argc != 4 || ft_strlen(argv[2]) != 1)
    {
        ft_putchar('\n');
    }
    else
    {
        ft_search(argv[1], argv[2][0], argv[3][0]);
        ft_putchar('\n');
    }
}