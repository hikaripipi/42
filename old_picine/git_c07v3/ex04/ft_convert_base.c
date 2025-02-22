/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:48:11 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/27 17:53:07 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_check_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to));
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
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

// int	main(void)
// {
// 	char *result;

// 	// テストケース1: 10進数から2進数への変換
// 	result = ft_convert_base("42", "0123456789", "01");
// 	printf("42 (base 10) to binary: %s\n", result);
// 	free(result);

// 	// テストケース2: 2進数から16進数への変換
// 	result = ft_convert_base("101010", "01", "0123456789ABCDEF");
// 	printf("101010 (base 2) to hex: %s\n", result);
// 	free(result);

// 	// テストケース3: 16進数から8進数への変換
// 	result = ft_convert_base("FF", "0123456789ABCDEF", "01234567");
// 	printf("FF (base 16) to octal: %s\n", result);
// 	free(result);

// 	// テストケース4: 負の数の変換
// 	result = ft_convert_base("-42", "0123456789", "0123456789ABCDEF");
// 	printf("-42 (base 10) to hex: %s\n", result);
// 	free(result);

// 	// テストケース5: 無効なベースの処理
// 	result = ft_convert_base("42", "01234567899", "01");
// 	if (result == NULL)
// 		printf("Invalid base handled correctly\n");
// 	else
// 		free(result);

// 	return (0);
// }