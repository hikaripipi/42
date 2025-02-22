/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:21:58 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/27 04:16:34 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_helper(char *result, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	result[0] = '\0';
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_length;
	int		i;

	total_length = 0;
	i = 0;
	if (size == 0)
	{
		result = (char *)malloc(1);
		result[0] = '\0';
		return (result);
	}
	while (i < size)
		total_length += ft_strlen(strs[i++]);
	total_length += ft_strlen(sep) * (size - 1);
	result = (char *)malloc(total_length + 1);
	if (!result)
		return (NULL);
	return (ft_strjoin_helper(result, strs, sep, size));
}

// int main(void)
// {
//     char *strings[] = {"Hello", "world", "this", "is", "C"};
//     char *separator = ",";
//     char *result;

//     // ft_strjoin関数を呼び出す
//     result = ft_strjoin(5, strings, separator);

//     // 結果を表示
//     if (result != NULL)
//     {
//         printf("Joined string: %s\n", result);
//         free(result); // メモリを解放
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }