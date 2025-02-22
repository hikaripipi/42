/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 03:11:04 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/27 03:20:18 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (size);
}

// int main(void)
// {
//     int *range;
//     int size;
//     int i;

//     // テストケース: min = 3, max = 7
//     size = ft_ultimate_range(&range, 3, 7);

//     // sizeが0より大きい場合、結果を出力
//     if (size > 0)
//     {
//         for (i = 0; i < size; i++)
//         {
//             printf("%d ", range[i]);
//         }
//         printf("\n");

//         // 使用が終わったらメモリを解放
//         free(range);
//     }
//     else if (size == 0)
//     {
//         printf("Range is empty (min >= max).\n");
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }