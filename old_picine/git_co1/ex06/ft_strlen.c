/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:50:15 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:18 by hshinaga         ###   ########.fr       */
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
