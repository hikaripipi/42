/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:16:17 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/11 02:23:09 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_chunk(int index, int lower, int upper)
{
	return (index >= lower && index <= upper);
}

int	get_chunk_threshold(int total_size, int chunk_count, int chunk_index)
{
	int	threshold;

	threshold = (total_size * (chunk_index + 1)) / chunk_count - 1;
	return (threshold);
}

int	count_elements_in_chunk(t_node *a, int lower, int upper)
{
	int	count;

	count = 0;
	while (a)
	{
		if (is_in_chunk(a->index, lower, upper))
			count++;
		a = a->next;
	}
	return (count);
}

void	move_to_top(t_node **stack, int index, char stack_name)
{
	int	size;
	int	rotate_count;

	size = stack_size(*stack);
	rotate_count = size - index;
	if (index < size / 2)
	{
		while (index-- > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (rotate_count-- > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

int	get_position_of_closest_in_chunk(t_node *stack, int lower, int upper)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= lower && stack->index <= upper)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
