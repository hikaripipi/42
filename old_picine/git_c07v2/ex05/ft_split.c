/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 04:09:55 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/27 04:16:20 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_charset(*str, charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_charset(*str, charset))
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

char	*allocate_word(char *str, char *charset)
{
	int		len;
	char	*word;

	len = 0;
	while (str[len] && !is_charset(str[len], charset))
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (--len >= 0)
		word[len] = str[len];
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words_count;
	int		i;

	words_count = count_words(str, charset);
	i = 0;
	result = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			result[i++] = allocate_word(str, charset);
			while (*str && !is_charset(*str, charset))
				str++;
		}
		else
		{
			str++;
		}
	}
	result[i] = NULL;
	return (result);
}

// int main(void)
// {
//     char **result;
//     char str[] = "Hello,world!This is C.";
//     char charset[] = ", !";
//     int i = 0;

//     result = ft_split(str, charset);
//     while (result[i])
//     {
//         printf("result[%d]: %s\n", i, result[i]);
//         free(result[i]);
//         i++;
//     }
//     free(result);
//     return 0;
// }