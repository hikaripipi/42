
#include <unistd.h>

void checka(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == 'a')
        {
            write(1, "a", 1);
            return;
        }
        i++;
    }
    
}
int main(int argc, char **argv)
{
    if(argc != 2)
        write(1, "a", 1);
    else
        checka(argv[1]);
    write(1, "\n", 1);
    return 0;
}