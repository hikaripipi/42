/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:43:00 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:09 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	a;

	a = 0;
	while (a < size)
	{
		i = tab[size - 1 - a];
		tab[size - 1 - a] = tab[a];
		tab[a] = i;
		a++;
		if (a >= size - 1 - a)
		{
			break ;
		}
	}
}

// int	main(void)
// {
// 	int	numbers[] = {1, 2, 3, 4, 5, 16};
// 	int	size;

// 	size = sizeof(numbers) / sizeof(numbers[0]);
// 	ft_rev_int_tab(numbers, size);
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d ", numbers[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
