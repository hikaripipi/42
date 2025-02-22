#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putza(void)
{
    char text;
    text = 'z';
    while(text > 'a' - 1)
    {
        if(text % 2 == 1)
        {
            ft_putchar(text - 32);
        }
        else
        {
            ft_putchar(text);
        }
        text--;
    }
}

int main(void)
{
    ft_putza();
}