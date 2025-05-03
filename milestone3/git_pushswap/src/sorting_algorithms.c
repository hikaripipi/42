/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:26:47 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/03 21:34:44 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int a = (*stack)->value;
	int b = (*stack)->next->value;
	int c = (*stack)->next->next->value;

	if (a > b && b < c && a < c) // 213
		sa(stack);
	else if (a > b && b > c) // 321
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c) // 312
		ra(stack);
	else if (a < b && b > c && a < c) // 132
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c) // 231
		rra(stack);
}