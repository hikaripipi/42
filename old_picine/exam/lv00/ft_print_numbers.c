
#include <unistd.h>
void putchar(char a)
{
    write(1, &a, 1);
}
void	ft_print_numbers(void)
{
    int i;
    
    i = 0;
    while(i < 10)
    {
        putchar(i + '0');
        i++;
    }

}

int main(void)
{
    ft_print_numbers();
}


