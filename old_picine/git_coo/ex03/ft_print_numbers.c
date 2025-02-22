/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:48:06 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/14 20:27:04 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int		num;
	char	c;

	num = 0;
	while (num <= 9)
	{
		c = num + '0';
		write(1, &c, 1);
		num++;
	}
}

// int	main(void)
// {
// 	ft_print_numbers();
// 	return (0);
// }
