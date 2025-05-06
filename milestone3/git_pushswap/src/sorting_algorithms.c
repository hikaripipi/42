/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:26:47 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/06 21:45:24 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
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
void	sort_four(t_node **stack_a, t_node **stack_b)
{
	move_to_top(stack_a, find_min_index(*stack_a), 'a'); // 最小をtopへ
	pb(stack_a, stack_b);                                // 最小を退避
	sort_three(stack_a);                                 // 残りをソート
	pa(stack_a, stack_b);                                // 戻して完成
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	move_to_top(stack_a, find_min_index(*stack_a), 'a');
	pb(stack_a, stack_b);
	move_to_top(stack_a, find_min_index(*stack_a), 'a');
	pb(stack_a, stack_b);
	sort_three(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

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
		move_to_top(b, max_index, 'b'); // rb or rrb
		pa(a, b);
	}
}

void	sort_large(t_node **a, t_node **b, int chunk_count)
{
	int total_size = stack_size(*a);
	int chunk_size = total_size / chunk_count;
	int i;

	for (i = 0; i < chunk_count; i++)
	{
		int lower = i * chunk_size;
		int upper = get_chunk_threshold(total_size, chunk_count, i);
		push_chunk(a, b, lower, upper);
	}
	restore_stack(a, b);
}