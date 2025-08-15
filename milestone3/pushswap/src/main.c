/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:43 by hshinaga          #+#    #+#             */
/*   Updated: 2025/08/15 23:48:08 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argv, &stack_a);
	check_duplicate(stack_a);
	assign_indices(stack_a);
	size = stack_size(stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	if (size > 1)
		sort_dispatch(&stack_a, &stack_b, size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
