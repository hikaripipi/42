/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:05:11 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:36:57 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
	{
		return (0);
	}
	if (nb == 2)
	{
		return (1);
	}
	if (nb % 2 == 0)
	{
		return (0);
	}
	i = 3;
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
	{
		return (2);
	}
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

// int	main(void)
// {
// 	int numbers[] = {-10, 0, 1, 2, 3, 4, 10, 17, 18, 24, 29, 30, 100, 200,
// 		2147483647};
// 	int num_tests = sizeof(numbers) / sizeof(numbers[0]);

// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		int result = ft_find_next_prime(numbers[i]);
// 		printf("ft_find_next_prime(%d) = %d\n", numbers[i], result);
// 	}

// 	return (0);
// }