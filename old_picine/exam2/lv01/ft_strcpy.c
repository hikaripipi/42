#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

char    *ft_strcpy(char *s1, char *s2)
{
    int i;
    i = 0;
    while(s2[i] != '\0' )
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);
}

int main (void)
{
    char a[] = "aaaaaa";
    char b[] = "bbbb";


    ft_strcpy(a, b);
    printf("%s", a);

}