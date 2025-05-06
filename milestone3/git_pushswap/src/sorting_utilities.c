/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:16:17 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/06 19:37:00 by hikarimac        ###   ########.fr       */
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

int	find_max_index(t_node *stack)
{
	int	max_index;
	int	index;
	int	count;

	max_index = stack->index;
	index = 0;
	count = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			index = count;
		}
		count++;
		stack = stack->next;
	}
	return (index);
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
int	get_node_position(t_node *stack, int target_index)
{
	int position = 0;

	while (stack)
	{
		if (stack->index == target_index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1); // 万が一見つからない場合
}