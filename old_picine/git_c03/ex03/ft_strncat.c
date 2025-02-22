/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:17:50 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/21 17:18:21 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (p < nb && src[p] != '\0')
	{
		dest[i] = src[p];
		i++;
		p++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main() {
//     char dest[50] = "Hello, ";
//     char *src = "World!";

//     // srcの前半3文字だけを連結
//     ft_strncat(dest, src, 3);

//     printf("Concatenated string: %s\n", dest);  // 出力: "Hello, Wor"

//     return (0);
// }
