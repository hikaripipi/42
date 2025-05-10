/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:22:17 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/10 22:29:46 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_node **a, t_node **b, int lower, int upper)
{
	int	count;

	count = count_elements_in_chunk(*a, lower, upper);
	while (count > 0)
	{
		if (is_in_chunk((*a)->index, lower, upper))
		{
			pb(a, b);
			count--;
		}
		else
			ra(a);
	}
}

void	restore_stack(t_node **a, t_node **b)
{
	int	max_index;

	while (*b)
	{
		max_index = find_max_index(*b);
		move_to_top(b, max_index, 'b');
		pa(a, b);
	}
}

void	sort_large(t_node **a, t_node **b, int chunk_count)
{
	int	total_size;
	int	chunk_size;
	int	i;
	int	lower;
	int	upper;

	i = 0;
	total_size = stack_size(*a);
	chunk_size = total_size / chunk_count;
	while (i < chunk_count)
	{
		lower = i * chunk_size;
		upper = get_chunk_threshold(total_size, chunk_count, i);
		push_chunk(a, b, lower, upper);
		i++;
	}
	restore_stack(a, b);
}
