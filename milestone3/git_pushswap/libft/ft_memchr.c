/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:20:57 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/04 19:31:06 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*memory;
	unsigned char		target;
	size_t				i;

	memory = (const unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (memory[i] == target)
			return ((void *)&memory[i]);
		i++;
	}
	return (NULL);
}
