/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:34:42 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:37:23 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	x;

	if (nb < 0)
	{
		return (0);
	}
	x = 1;
	while (x * x <= nb && x < 46341)
	{
		if (x * x == nb)
		{
			return (x);
		}
		x++;
	}
	return (0);
}

// int	main(void)
// {
// 	int	numbers[] = {-1, 0, 1, 4, 15, 16, 25, 36, 100, 2147395600, 2147483647};
// 	int	num_tests;
// 	int	result;

// 	// テストケース
// 	num_tests = sizeof(numbers) / sizeof(numbers[0]);
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		result = ft_sqrt(numbers[i]);
// 		printf("ft_sqrt(%d) = %d\n", numbers[i], result);
// 	}
// 	return (0);
// }
