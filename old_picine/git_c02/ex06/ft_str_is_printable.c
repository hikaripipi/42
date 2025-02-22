/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:28:44 by hikarimac         #+#    #+#             */
/*   Updated: 2024/08/20 02:03:33 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] < 32 || str[i] > 126))
			return (0);
		i++;
	}
	return (1);
}

// int main(void)
// {
//     // テストケース
//     char src1[] = "Hell1o"; // 表示可能な文字のみ
//     char src2[] = "Hello\n"; // 非表示文字が含まれている
//     char src3[] = ""; // 空文字列
//     char src4[] = "Hello 123!"; // 表示可能な文字のみ

//     printf("Test 1: %d\n", ft_str_is_printable(src1)); // 期待値: 1
//     printf("Test 2: %d\n", ft_str_is_printable(src2)); // 期待値: 0
//     printf("Test 3: %d\n", ft_str_is_printable(src3)); // 期待値: 1
//     printf("Test 4: %d\n", ft_str_is_printable(src4)); // 期待値: 1

//     return 0;
// }