/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:07:49 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/12 22:18:39 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	put_number(long long n, char *base, int base_len)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= base_len)
	{
		ret = put_number(n / base_len, base, base_len);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = write(1, &base[n % base_len], 1);
	if (ret == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr_base(long long n, char *base)
{
	int		base_len;
	int		count;
	int		ret;

	count = 0;
	if (n < 0)
	{
		ret = write(1, "-", 1);
		if (ret == -1)
			return (-1);
		n = -n;
		count = 1;
	}
	base_len = ft_strlen(base);
	ret = put_number(n, base, base_len);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
