/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:34:48 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/20 19:57:54 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	// テストケース1: 完全に同じ文字列
// 	char str1[] = "Hello";
// 	char str2[] = "Hello";
// 	printf("Test 1: %d\n", ft_strcmp(str1, str2)); // 期待値: 0

// 	// テストケース2: 1文字目が異なる文字列
// 	char str3[] = "Hello";
// 	char str4[] = "hello";
// 	printf("Test 2: %d\n", ft_strcmp(str3, str4));
// 		// 期待値: 負の値 (大文字の 'H' と小文字の 'h' の差)

// 	// テストケース3: 部分一致の文字列
// 	char str5[] = "Hello";
// 	char str6[] = "Hel";
// 	printf("Test 3: %d\n", ft_strcmp(str5, str6));
// 		// 期待値: 正の値 ('l' と終端文字 '\0' の差)

// 	// テストケース4: 空文字列と非空文字列の比較
// 	char str7[] = "";
// 	char str8[] = "Hello";
// 	printf("Test 4: %d\n", ft_strcmp(str7, str8)); // 期待値: 負の値 ('\0' と 'H' の差)

// 	// テストケース5: 非空文字列と空文字列の比較
// 	char str9[] = "Hello";
// 	char str10[] = "";
// 	printf("Test 5: %d\n", ft_strcmp(str9, str10)); // 期待値: 正の値 ('H' と '\0' の差)

// 	// テストケース6: 異なる長さの文字列
// 	char str11[] = "abcde";
// 	char str12[] = "abcdef";
// 	printf("Test 6: %d\n", ft_strcmp(str11, str12)); // 期待値: 負の値 ('\0' と 'f' の差)

// 	return (0);
// }