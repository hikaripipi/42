/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:02:51 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/04 20:02:40 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	target;

	target = (char)c;
	while (*str)
	{
		if (*str == target)
			return ((char *)str);
		str++;
	}
	if (target == '\0')
		return ((char *)str);
	return (NULL);
}
