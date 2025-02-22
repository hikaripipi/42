/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:49:53 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:41 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int	main(void)
// {
// 	int	c;
// 	int	d;

// 	c = 5;
// 	d = 10;
// 	printf("A = % d, B = % d", c, d);
// 	ft_swap(&A, &B);
// 	printf("A = % d, B = % d", c, d);
// 	return (0);
// }
