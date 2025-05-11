/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:20:14 by hikarimac         #+#    #+#             */
/*   Updated: 2025/05/12 00:45:48 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_node **stack, t_node *new)
{
	t_node	*current;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	parse_args(char **argv, t_node **stack_a)
{
	int		i;
	long	tmp_num;
	int		num;
	t_node	*new;

	i = 1;
	while (argv[i])
	{
		if (!is_valid_integer(argv[i]))
			error_exit();
		tmp_num = ft_atol(argv[i]);
		if (tmp_num < INT_MIN || tmp_num > INT_MAX)
			error_exit();
		num = (int)tmp_num;
		new = create_node(num);
		append_node(stack_a, new);
		i++;
	}
	check_duplicate(*stack_a);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
