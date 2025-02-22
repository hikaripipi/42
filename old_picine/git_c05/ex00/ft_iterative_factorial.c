/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:47:37 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:38:04 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
	{
		return (0);
	}
	result = 1;
	while (nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

// int	main(void)
// {
// 	// テストケース
// 	int numbers[] = {-1, 0, 1, 3, 5, 10};
// 	int num_tests = sizeof(numbers) / sizeof(numbers[0]);

// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		int result = ft_iterative_factorial(numbers[i]);
// 		printf("ft_iterative_factorial(%d) = %d\n", numbers[i], result);
// 	}

// 	return (0);
// }