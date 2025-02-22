#include <unistd.h>

void putchar(a)
{
    write(1, &a, 1);
}

void putaz(void)
{
    int i;
    i = 0;
    while(i < 26)
    {
        if(i % 2 == 0)
            putchar(i + 'a');
        else
            putchar(i + 'a' - 32);
        i++;
    }
}

int main(void)
{
    putaz();
}