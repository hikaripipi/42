/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:57:32 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/10 23:06:25 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_node_position(t_node *stack, int target_index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}
