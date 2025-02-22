#include <unistd.h>

void putchar(char a)
{
    write(1, &a, 1);
}
void putstr(char *str)
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

    str = "Hello World!";
    putstr(str);
}