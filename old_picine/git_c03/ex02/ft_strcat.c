/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:57:22 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/21 15:16:41 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[p] != '\0')
	{
		dest[i] = src[p];
		i++;
		p++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void) {
//     // 十分なサイズのバッファを持つdestを宣言
//     char dest[50] = "Hello, ";
//     char *src = "World!";

//     // ft_strcat 関数を呼び出して、src を dest に連結
//     ft_strcat(dest, src);

//     // 結果を表示
//     printf("Concatenated string: %s\n", dest);

//     return (0);
// }