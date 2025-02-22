
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putaz(void)
{
    char text;
    text = 'a';

    while(text != ('z' + 1) )
    {
        if(text % 2 == 0)
        {
            ft_putchar(text - 32);
        }
        else
        {
            ft_putchar(text);
        }
        text++;
    }
}

int main(void)
{
    ft_putaz();
}