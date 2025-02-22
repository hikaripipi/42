/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:09:09 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/20 02:03:43 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	// テストケース
// 	char src1[] = "AAAA"; // 大文字のみ
// 	char src2[] = "Hello, WORLD!"; // 大文字と小文字が混在
// 	char src3[] = "12345"; // 数字のみ
// 	char src4[] = ""; // 空文字列
// 	char src5[] = "already lower"; // 既に小文字

// 	printf("Test 1: %s\n", ft_strlowcase(src1)); // 期待値: "aaaa"
// 	printf("Test 2: %s\n", ft_strlowcase(src2)); // 期待値: "hello, world!"
// 	printf("Test 3: %s\n", ft_strlowcase(src3)); // 期待値: "12345"
// 	printf("Test 4: %s\n", ft_strlowcase(src4)); // 期待値: ""
// 	printf("Test 5: %s\n", ft_strlowcase(src5)); // 期待値: "already lower"

// 	return (0);
// }