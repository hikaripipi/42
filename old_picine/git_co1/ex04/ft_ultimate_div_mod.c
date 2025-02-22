/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:34:45 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:30 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *a / *b;
	*b = i % *b;
}

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 10;
// 	b = 5;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("a = %d, B = %d", a, b);
// }
