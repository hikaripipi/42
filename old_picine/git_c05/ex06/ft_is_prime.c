/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:54:58 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:37:07 by hshinaga         ###   ########.fr       */
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

// int	main(void)
// {
// 	int	numbers[] = {0, 1, 2, 3, 4, 5, 10, 13, 17, 18, 19, 25, 29, 37, 100,
// 			101};
// 	int	num_tests;
// 	int	result;

// 	// テストケース
// 	num_tests = sizeof(numbers) / sizeof(numbers[0]);
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		result = ft_is_prime(numbers[i]);
// 		printf("ft_is_prime(%d) = %d\n", numbers[i], result);
// 	}
// 	return (0);
// }
