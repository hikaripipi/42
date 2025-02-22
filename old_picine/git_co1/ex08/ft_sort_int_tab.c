/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:09:06 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:04 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	int numbers1[] = {5, 3, 8, 4, 2};
// 	int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
// 	printf("Before sorting: ");
// 	for (int i = 0; i < size1; i++)
// 		printf("%d ", numbers1[i]);
// 	printf("\n");

// 	ft_sort_int_tab(numbers1, size1);

// 	printf("After sorting:  ");
// 	for (int i = 0; i < size1; i++)
// 		printf("%d ", numbers1[i]);
// 	printf("\n\n");
// }