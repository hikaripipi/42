/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:16:17 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/04 01:19:43 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_node *stack)
{
	int	min;
	int	count;
	int	index;

	min = stack->value;
	count = 0;
	index = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = count;
		}
		count++;
		stack = stack->next;
	}
	return (index);
}

void	move_to_top(t_node **stack, int index)
{
	int size = stack_size(*stack);
	int r = size - index;

	if (index < size / 2)
	{
		while (index-- > 0)
			ra(stack);
	}
	else
	{
		while (r-- > 0)
			rra(stack);
	}
}