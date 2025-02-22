/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:11:55 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/19 21:01:24 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[1] == '\0')
		return (1);
	while (str[i] && str[i] != '\0')
	{
		if ((str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char src[] = "AAB";

// 	printf("%d", ft_str_is_uppercase(src));
// 	return (0);
// }