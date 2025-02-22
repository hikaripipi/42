#include <unistd.h>

char putchar(char a)
{
    write(1, &a, 1);
    return 0;
}
void putnum(n)
{
    if(n >= 10)
        putnum(n / 10);
    putchar((n %10) +'0');
}

void print1_100(void)
{
    int i;
    i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            if (i % 3 == 0)
                write(1, "fizz", 4);
            if (i % 5 == 0)
                write(1, "buzz", 4);
        }
        else
            putnum(i);
        putchar('\n');
        i++;
    }
}

int main(void)
{
    print1_100();
    return 0;
}