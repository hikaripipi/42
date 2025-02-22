#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rot13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			ft_putchar(((str[i] - 'A' + 13) % 26) + 'A');
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			ft_putchar(((str[i] - 'a' + 13) % 26) + 'a');
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
	}
	else
	{
		ft_rot13(argv[1]);
		ft_putchar('\n');
	}
}