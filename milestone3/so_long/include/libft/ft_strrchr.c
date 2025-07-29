/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:58:03 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/06 00:17:47 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;
	char		target;

	last = NULL;
	target = (char)c;
	while (*str)
	{
		if (*str == target)
			last = str;
		str++;
	}
	if (target == '\0')
		return ((char *)str);
	return ((char *)last);
}
