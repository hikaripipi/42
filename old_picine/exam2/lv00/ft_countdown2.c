#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(void)
{
    int i;
    i = 9;
    while(i >= 0)
    {
        ft_putchar(i + '0');
        i--;
    }
}

int main(void)
{
    ft_putstr();
}