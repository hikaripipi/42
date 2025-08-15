/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:13:08 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 23:48:08 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tokens(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	error_exit_cleanup(t_node **stack, char **tokens)
{
	if (tokens)
		free_tokens(tokens);
	if (stack && *stack)
		free_stack(*stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_duplicate(t_node *stack)
{
	t_node	*current;
	t_node	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
				error_exit_cleanup(&stack, NULL);
			runner = runner->next;
		}
		current = current->next;
	}
}
