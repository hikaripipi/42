/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:08:29 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/14 20:26:56 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int numbers[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(numbers[i] + '0');
		i++;
	}
}

void	ft_increment_numbers(int numbers[], int n)
{
	int	i;

	i = n - 1;
	while (i >= 0 && numbers[i] == 9 - (n - 1) + i)
		i--;
	numbers[i]++;
	i++;
	while (i < n)
	{
		numbers[i] = numbers[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	numbers[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		numbers[i] = i;
		i++;
	}
	while (1)
	{
		ft_print_numbers(numbers, n);
		if (numbers[0] == 10 - n)
			break ;
		ft_putchar(',');
		ft_putchar(' ');
		ft_increment_numbers(numbers, n);
	}
}

// int	main(void)
// {
// 	ft_print_combn(3);
// }
