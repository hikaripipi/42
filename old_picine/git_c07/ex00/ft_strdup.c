/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:38:37 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/27 19:11:28 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;
	int		i;

	if (src == NULL)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	*original;
// 	char	*duplicate;

// 	// テストするための文字列を定義
// 	original = "Hello, World!";
// 	// ft_strdupを使って文字列を複製
// 	duplicate = ft_strdup(original);
// 	// 複製が成功したか確認
// 	if (duplicate != NULL)
// 	{
// 		// 結果を出力
// 		printf("Original: %s\n", original);
// 		printf("Duplicate: %s\n", duplicate);
// 		// メモリを解放
// 		free(duplicate);
// 	}
// 	else
// 	{
// 		// エラー時のメッセージを表示
// 		printf("Failed to allocate memory.\n");
// 	}
// 	return (0);
// }
