/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:20:14 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 23:42:57 by hikarimac        ###   ########.fr       */
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

static void	free_strarray(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	parse_args(char **argv, t_node **stack_a)
{
	int		i;
	char	**tokens;

	i = 1;
	while (argv[i])
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			error_exit_cleanup(stack_a, tokens);
		parse_tokens(tokens, stack_a);
		free_strarray(tokens);
		i++;
	}
	check_duplicate(*stack_a);
}

void	parse_tokens(char **tokens, t_node **stack_a)
{
	int		j;
	long	tmp_num;
	int		num;
	t_node	*new;

	j = 0;
	while (tokens[j])
	{
		if (!is_valid_integer(tokens[j]))
			error_exit_cleanup(stack_a, tokens);
		tmp_num = ft_atol(tokens[j]);
		if (tmp_num < INT_MIN || tmp_num > INT_MAX)
			error_exit_cleanup(stack_a, tokens);
		num = (int)tmp_num;
		new = create_node(num);
		if (!new)
			error_exit_cleanup(stack_a, tokens);
		append_node(stack_a, new);
		j++;
	}
}
