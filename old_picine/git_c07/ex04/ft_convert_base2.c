/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:48:23 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/27 17:52:23 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_process_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;
	int	j;
	int	base_len;

	result = 0;
	i = 0;
	base_len = ft_strlen(base);
	sign = ft_process_sign(str, &i);
	while (str[i])
	{
		j = 0;
		while (base[j] && base[j] != str[i])
			j++;
		if (!base[j])
			break ;
		result = result * base_len + j;
		i++;
	}
	return (result * sign);
}

static int	ft_get_num_len(long n, int base_len)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, char *base_to)
{
	char	*result;
	long	n;
	int		len;
	int		base_len;

	base_len = ft_strlen(base_to);
	n = nbr;
	len = ft_get_num_len(n, base_len);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		n = -n;
	while (len > 0)
	{
		len--;
		result[len] = base_to[n % base_len];
		n /= base_len;
	}
	if (nbr < 0)
		result[0] = '-';
	return (result);
}
