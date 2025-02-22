/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:14:45 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/23 22:14:58 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

// int	main(void)
// {
// 	int		i;
// 	char	*a;

// 	a = "aaaaaaaa";
// 	i = ft_strlen(a);
// 	printf("text len = %d", i);
// 	return (0);
// }
