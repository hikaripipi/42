/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 03:54:46 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/20 02:03:21 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char src1[] = "12345";
// 	char src2[] = "123a45";
// 	char src3[] = "";
// 	printf("%d\n", ft_str_is_numeric(src1)); // 1 を期待
// 	printf("%d\n", ft_str_is_numeric(src2)); // 0 を期待
// 	printf("%d\n", ft_str_is_numeric(src3)); // 1 を期待
// 	return (0);
// }