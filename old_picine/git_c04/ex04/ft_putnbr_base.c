/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:52:06 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/24 18:51:04 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
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
	return (i > 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		base_len;

	num = nbr;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (!is_valid_base(base))
		return ;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= base_len)
	{
		ft_putnbr_base(num / base_len, base);
		ft_putnbr_base(num % base_len, base);
	}
	else
		ft_putchar(base[num]);
}

// int	main(void)
// {
// 	ft_putnbr_base(-2147483648, "01");
// 	ft_putchar('\n');
// 	ft_putnbr_base(255, "0123456789ABCDEF");
// 	ft_putchar('\n');
// 	ft_putnbr_base(-42, "poneyvif");
// 	ft_putchar('\n');
// 	return (0);
// }
