
#include <unistd.h>
void putchar(char a)
{
    write(1, &a, 1);
}
void countdown(int n)
{
    while(n + 1)
    {
        putchar(n + '0');
        n--;
    }

}



int main(void)
{
    countdown(9);
}
