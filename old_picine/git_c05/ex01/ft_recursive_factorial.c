/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:51:05 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:37:56 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

// int	main(void)
// {
// 	int	numbers[] = {-1, 0, 1, 3, 5, 10};
// 	int	num_tests;
// 	int	result;

// 	// テストケース
// 	num_tests = sizeof(numbers) / sizeof(numbers[0]);
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		result = ft_recursive_factorial(numbers[i]);
// 		printf("ft_recursive_factorial(%d) = %d\n", numbers[i], result);
// 	}
// 	return (0);
// }
