/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:16:17 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/06 17:12:40 by hikarimac        ###   ########.fr       */
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
	int	size;
	int	r;

	size = stack_size(*stack);
	r = size - index;
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

void	assign_indices(t_node *stack)
{
	int		index_to_assign;
	t_node	*current;
	t_node	*smallest;

	index_to_assign = 0;
	while (1)
	{
		smallest = NULL;
		current = stack;
		while (current != NULL)
		{
			if (current->index == -1)
			{
				if (smallest == NULL || current->value < smallest->value)
					smallest = current;
			}
			current = current->next;
		}
		if (smallest == NULL)
			break ;
		smallest->index = index_to_assign;
		index_to_assign++;
	}
}

int	get_chunk_threshold(int total_size, int chunk_count, int chunk_index)
{
	int	threshold;

	threshold = (total_size * (chunk_index + 1)) / chunk_count - 1;
	return (threshold);
}

int	is_in_chunk(int index, int lower, int upper)
{
	return (index >= lower && index <= upper);
}
