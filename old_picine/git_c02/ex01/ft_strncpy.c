/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 03:09:27 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/19 20:57:44 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "Hello";
// 	char dest[20] = "HikariShinagawa";
// 	unsigned int n;

// 	n = 5;

// 	ft_strncpy(dest, src, n);
// 	printf("Copied string: %s\n", dest);

// 	return (0);
// }