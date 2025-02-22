/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:00:09 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/24 23:08:37 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

// int main(void) {
//     // テストケース
//     int numbers[][2] = {{2, 3}, {5, 0}, {0, 0}, {10, -2}, {2, 10}, {-2, 3}};
//     int num_tests = sizeof(numbers) / sizeof(numbers[0]);

//     for (int i = 0; i < num_tests; i++) {
//         int nb = numbers[i][0];
//         int power = numbers[i][1];
//         int result = ft_iterative_power(nb, power);
//         printf("ft_iterative_power(%d, %d) = %d\n", nb, power, result);
//     }

//     return (0);
// }