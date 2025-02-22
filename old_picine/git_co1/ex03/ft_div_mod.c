/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:34:45 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:35 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int	main(void)
// {
// 	int	c;
// 	int	d;
// 	int	div;
// 	int	mod;

// 	c = 5;
// 	d = 2;
// 	ft_div_mod(c, d, &div, &mod);
// 	printf("div = %d, mod = %d", div, mod);
// 	return (0);
// }
