/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:54:31 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/27 04:16:47 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

// int	main(void)
// {
// 	int min = 3;
// 	int max = 7;
// 	int *range;
// 	int i;

// 	range = ft_range(min, max);

// 	if (range != NULL)
// 	{
// 		// 配列の内容を表示
// 		printf("Range from %d to %d (excluding %d):\n", min, max - 1, max);
// 		for (i = 0; i < (max - min); i++)
// 		{
// 			printf("%d ", range[i]);
// 		}
// 		printf("\n");

// 		free(range);
// 	}
// 	else
// 	{
// 		printf("Range is NULL (min >= max)\n");
// 	}

// 	return (0);
// }