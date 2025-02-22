/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:29:58 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/21 17:16:50 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello, World!";
// 	char	to_find[] = "Wor";
// 	char	*result;

// 	result = ft_strstr(str, to_find);
// 	if (result != NULL)
// 	{
// 		printf("Found: %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Not found.\n");
// 	}
// 	return (0);
// }
