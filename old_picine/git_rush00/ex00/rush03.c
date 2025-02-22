/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rytanaka <rytanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:58:00 by rytanaka          #+#    #+#             */
/*   Updated: 2024/08/10 16:30:09 by rytanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top_bottom_putchar(int x)
{
	int	count_x;

	count_x = 0;
	while (count_x < x)
	{
		if (count_x == 0)
		{
			ft_putchar('A');
		}
		else if (count_x == x - 1)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		count_x++;
	}
}

void	side_putchar(int x)
{
	int	count_x;

	count_x = 0;
	while (count_x < x)
	{
		if (count_x == 0 || count_x == x - 1)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		count_x++;
	}
}

void	rush(int x, int y)
{
	int	count_y;

	count_y = 0;
	while (count_y < y)
	{
		if (count_y == 0 || count_y == y - 1)
		{
			top_bottom_putchar(x);
		}
		else
		{
			side_putchar(x);
		}
		ft_putchar('\n');
		count_y++;
	}
}
