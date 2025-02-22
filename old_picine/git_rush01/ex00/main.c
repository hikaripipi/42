/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 02:11:29 by ysasai            #+#    #+#             */
/*   Updated: 2024/08/18 21:23:13 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	print_grid(int grid[4][4]);
int		solve_skyscraper(int grid[4][4], int *views, int row, int col);

int	is_valid_number(char *str)
{
	if (*str < '1' || *str > '4')
		return (0);
	return (1);
}

int	process_input(char *input, int *views)
{
	int	i;

	i = 0;
	while (*input && i < 16)
	{
		if (!is_valid_number(input))
			return (0);
		views[i++] = *input - '0';
		input++;
		if (*input && *input != ' ')
			return (0);
		if (*input)
			input++;
	}
	return (i == 16 && !*input);
}

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	views[16];
	int	grid[4][4];

	if (argc != 2 || !process_input(argv[1], views))
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_grid(grid);
	if (solve_skyscraper(grid, views, 0, 0))
		print_grid(grid);
	else
		ft_putstr("Error\n");
	return (0);
}
