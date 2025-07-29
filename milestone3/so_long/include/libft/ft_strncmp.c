/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:38:14 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/05 17:42:39 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (len == 0)
		return (0);
	while (i < len - 1)
	{
		c1 = (unsigned char)str1[i];
		c2 = (unsigned char)str2[i];
		if (c1 == '\0' || c2 == '\0' || c1 != c2)
			break ;
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
