#include <unistd.h>

void putchar(char a)
{
    write(1, &a, 1);
}


void    putstr (char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
}


char    *ft_strcpy(char *s1, char *s2)
{
    int i;
    i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);

}

int main(void)
{
    char a[20] = "aaaa";
    char *b;
    char *c;

    b = "bb";
    putstr(a);
    putchar('\n');
    c = ft_strcpy(a, b);
    putstr(c);
}