#include <stdio.h>

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

int main(void)
{
    char *a;
    int len;
    a = "love";
    len = ft_strlen(a);
    printf("%d", len);
}

