#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_repeat_alpha(char *str)
{
    int i;
    int j;
    int index;
    i = 0;

    while(str[i] != '\0')
    {
        
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i] - 'A' + 1;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            index = str[i] - 'a' + 1;
        }
        else 
            index = 1;

        j = 0;
        while(j < index)
        {
            ft_putchar(str[i]);
            j++;
        }
        i++;
    }
}
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        ft_putchar('\n');
    }
    else
    {
        ft_repeat_alpha(argv[1]);
        ft_putchar('\n');
    }
}