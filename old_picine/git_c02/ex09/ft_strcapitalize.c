/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:08:28 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/20 02:22:55 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isspace(char c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && !(c >= '0'
			&& c <= '9'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	space;

	space = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			space = 1;
		}
		else
		{
			if (space == 1 && str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			if (space == 0 && str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
			space = 0;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	// テストケース
// 	char src1[] = "salut,comment tu vas ? ";
// 	char src2[] = "heLLo, WoRLd!"; // 大文字と小文字が混在
// 	char src3[] = "123HELLO"; // 数字とアルファベットが混在
// 	char src4[] = ""; // 空文字列

// 	printf("Test 1: %s\n", ft_strcapitalize(src1));
// 	printf("Test 2: %s\n", ft_strcapitalize(src2)); // 期待値: "Hello, World!"
// 	printf("Test 3: %s\n", ft_strcapitalize(src3)); // 期待値: "123hello"
// 	printf("Test 4: %s\n", ft_strcapitalize(src4)); // 期待値: ""
// 	return (0);
// }