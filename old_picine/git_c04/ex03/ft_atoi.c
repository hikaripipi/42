/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:21:33 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/24 18:30:01 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// int	main(int argc, char **argv)
// {
// 	int result;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <number_string>\n", argv[0]);
// 		return (1);
// 	}
// 	result = ft_atoi(argv[1]);
// 	printf("%d\n", result);
// 	return (0);
// }