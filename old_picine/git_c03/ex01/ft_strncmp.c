/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:58:49 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/21 17:18:07 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

// int main(void)
// {
//     // テストケース1: 同じ文字列、nが文字列の長さより大きい
//     printf("Test 1: %d\n", ft_strncmp("Hello", "Hello", 10)); // 期待値: 0

//     // テストケース2: 同じ文字列、nが一部のみ比較
//     printf("Test 2: %d\n", ft_strncmp("Hello", "Hello", 3));  // 期待値: 0

//     // テストケース3: 異なる文字列、最初の文字が違う
//     printf("Test 3: %d\n", ft_strncmp("Hello", "World", 5));  // 期待値: 負の値

//     // テストケース4: 異なる文字列、nが異なる部分をカバー
//     printf("Test 4: %d\n", ft_strncmp("Hello", "HeLlo", 3));  // 期待値: 0

//     // テストケース5: 異なる文字列、nが異なる部分までカバー
//     printf("Test 5: %d\n", ft_strncmp("Hello", "HeLlo", 5)); 
	// 期待値: 正の値（'l' と 'L' の差）

//     // テストケース6: 片方が短い文字列
//     printf("Test 6: %d\n", ft_strncmp("Hello", "Hel", 5));   
	// 期待値: 正の値（'l' と '\0' の差）

//     // テストケース7: 空文字列との比較
//     printf("Test 7: %d\n", ft_strncmp("", "Hello", 5));      
	// 期待値: 負の値（'\0' と 'H' の差）

//     return (0);
// }