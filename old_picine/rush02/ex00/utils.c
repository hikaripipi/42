/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:54:36 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 23:11:35 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include <limits.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_greater_than_max(const char *str)
{
	const char	*max_str = "18446744073709551615";
	int			len;
	int			max_len;

	len = ft_strlen(str);
	max_len = ft_strlen(max_str);
	if (len > max_len)
		return (1);
	if (len < max_len)
		return (0);
	return (strcmp(str, max_str) > 0);
}

unsigned long long	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
