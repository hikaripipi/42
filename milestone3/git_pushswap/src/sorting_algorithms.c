/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:26:47 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/05 03:27:00 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	move_to_top(stack_a, find_min_index(*stack_a));
	pb(stack_a, stack_b);
	move_to_top(stack_a, find_min_index(*stack_a));
	pb(stack_a, stack_b);
	sort_three(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}