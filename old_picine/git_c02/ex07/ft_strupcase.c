/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:50:04 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/20 02:03:37 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	// テストケース
// 	char src1[] = "aaaa"; // 小文字のみ
// 	char src2[] = "Hello, World!"; // 大文字と小文字が混在
// 	char src3[] = "12345"; // 数字のみ
// 	char src4[] = ""; // 空文字列
// 	char src5[] = "ALREADY UPPER"; // 既に大文字

// 	printf("Test 1: %s\n", ft_strupcase(src1)); // 期待値: "AAAA"
// 	printf("Test 2: %s\n", ft_strupcase(src2)); // 期待値: "HELLO, WORLD!"
// 	printf("Test 3: %s\n", ft_strupcase(src3)); // 期待値: "12345"
// 	printf("Test 4: %s\n", ft_strupcase(src4)); // 期待値: ""
// 	printf("Test 5: %s\n", ft_strupcase(src5)); // 期待値: "ALREADY UPPER"

// 	return (0);
// }