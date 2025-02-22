/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:00:27 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/24 18:42:52 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;

	i = 0;
	sign = 1;
	result = 0;
	if (!check_base(base))
		return (0);
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	base_len = ft_strlen(base);
	while (get_value(str[i], base) != -1)
	{
		result = result * base_len + get_value(str[i], base);
		i++;
	}
	return (result * sign);
}

// int	main(void)
// {
// 	// テストケース1: 10進数の文字列を整数に変換
// 	printf("Test 1: %d\n", ft_atoi_base("42", "0123456789")); // 期待結果: 42

// 	// テストケース2: 負の16進数の文字列を整数に変換
// 	printf("Test 2: %d\n", ft_atoi_base("-1A", "0123456789ABCDEF"));

// 	// テストケース3: 2進数の文字列を整数に変換
// 	printf("Test 3: %d\n", ft_atoi_base("1010", "01")); // 期待結果: 10

// 	// テストケース4: 無効なベース（重複文字）
// 	printf("Test 4: %d\n", ft_atoi_base("42", "01234456789")); // 期待結果: 0

// 	// テストケース5: 無効な文字列（ベースに含まれない文字）
// 	printf("Test 5: %d\n", ft_atoi_base("42A", "0123456789")); // 期待結果: 0

// 	// テストケース6: カスタムベース (poneyvif)
// 	printf("Test 6: %d\n", ft_atoi_base("noney", "poneyvif")); // 期待結果: 42

// 	// テストケース7: 空の文字列
// 	printf("Test 7: %d\n", ft_atoi_base("", "0123456789")); // 期待結果: 0

// 	// テストケース8: 無効なベース（1文字以下）
// 	printf("Test 8: %d\n", ft_atoi_base("42", "0")); // 期待結果: 0

// 	// テストケース9: 余分な空白と符号
// 	printf("Test 9: %d\n", ft_atoi_base("   -1010", "01")); // 期待結果: -10

// 	return (0);
// }
