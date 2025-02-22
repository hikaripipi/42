/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:31:02 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:37:32 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int	main(void)
// {
// 	int	indices[] = {-1, 0, 1, 2, 3, 5, 10, 15};
// 	int	num_tests;
// 	int	result;

// 	// テストケース
// 	num_tests = sizeof(indices) / sizeof(indices[0]);
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		result = ft_fibonacci(indices[i]);
// 		printf("ft_fibonacci(%d) = %d\n", indices[i], result);
// 	}
// 	return (0);
// }
