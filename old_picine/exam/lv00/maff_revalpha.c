#include <unistd.h>

void putchar(char a)
{
    write(1, &a, 1);
}

void putza(void)
{
    int i;
    i = 0;

    while(i < 26)
    {
        if(i % 2 == 1)
            putchar('z' - i -32);
        else
            putchar('z' - i);
        i++;
    }
}

int main(void)
{
    putza();
}