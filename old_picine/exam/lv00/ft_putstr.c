
#include <unistd.h>

char putchar(char a)
{
    write(1, &a, 1);
    return 0;
}

void	ft_putstr(char *str)
{
    int i;

    i = 0;

    while(str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
}



int main(void)
{
    char *str;
     
    str = "happy";
    ft_putstr(str);
}