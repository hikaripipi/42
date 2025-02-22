/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:13:20 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:37:43 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}

// int	main(void)
// {
// 	int	numbers[][2] = {{2, 3}, {5, 0}, {2, -2}, {3, 4}, {0, 0}, {10, 2}};
// 	int	num_tests;
// 	int	result;

// 	// テストケース
// 	num_tests = sizeof(numbers) / sizeof(numbers[0]);
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		result = ft_recursive_power(numbers[i][0], numbers[i][1]);
// 		printf("ft_recursive_power(%d, %d) = %d\n", numbers[i][0],
// 			numbers[i][1], result);
// 	}
// 	return (0);
// }
