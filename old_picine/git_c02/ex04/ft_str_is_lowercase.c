/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:03:53 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/20 02:03:27 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z'))
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char src1[] = "abcdef";
// 	char src2[] = "abcDef";
// 	char src3[] = "";

// 	printf("%d\n", ft_str_is_lowercase(src1)); // 1 を期待
// 	printf("%d\n", ft_str_is_lowercase(src2)); // 0 を期待
// 	printf("%d\n", ft_str_is_lowercase(src3)); // 1 を期待
// 	return (0);
// }