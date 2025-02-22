
#include <unistd.h>

char	putchar(char a)
{
	write(1, &a, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	while ((str[i] != 32 && str[i] != 9) && *str)
	{
		putchar(str[i]);
		i++;
	}
}
int	main(int argc, char **argv)
{
	if (argc > 2)
		putchar('\n');
	else
		ft_putstr(argv[1]);
	return (0);
}
