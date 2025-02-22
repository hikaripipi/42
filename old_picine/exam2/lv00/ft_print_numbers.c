#include <unistd.h>

void putchar(char c)
{
    write(1, &c, 1);
}

void putstr(void)
{
    int i;
    i = 0;
    while(i <= 9)
    {
        putchar(i + '0');
        i++;
    }
}

int main(void)
{
    putstr();
}