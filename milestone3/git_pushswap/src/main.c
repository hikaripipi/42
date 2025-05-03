/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:43 by hshinaga          #+#    #+#             */
/*   Updated: 2025/05/03 21:36:07 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <limits.h> // INT_MIN, INT_MAX

// スタックの中身を出力する補助関数
void	print_stack(t_node *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

// int main(void)
// {
//     // スタックA: 1 → 2 → 3
//     t_node *a = create_node(1);
//     a->next = create_node(2);
//     a->next->next = create_node(3);

//     // スタックB: 4 → 5 → 6
//     t_node *b = create_node(4);
//     b->next = create_node(5);
//     b->next->next = create_node(6);

//     printf("Before:\n");
//     print_stack(a, "A");
//     print_stack(b, "B");

//     // ========================
//     // 全スタック操作を1回ずつ実行
//     // ========================

//     sa(&a);
//     sb(&b);
//     ss(&a, &b);
//     pa(&a, &b);
//     pb(&a, &b);
//     ra(&a);
//     rb(&b);
//     rr(&a, &b);
//     rra(&a);
//     rrb(&b);
//     rrr(&a, &b);

//     printf("After:\n");
//     print_stack(a, "A");
//     print_stack(b, "B");

//     free_stack(a);
//     free_stack(b);
//     return (0);
// }

void	append_node(t_node **stack, t_node *new)
{
	t_node	*current;

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

int	main(int argc, char **argv)
{
	int		i;
	long	tmp_num;
	int		num;
	t_node	*stack_a;
	t_node	*new;

	if (argc < 2)
		error_exit();
	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (!is_valid_integer(argv[i]))
			error_exit();
		tmp_num = ft_atol(argv[i]);
		if (tmp_num < INT_MIN || tmp_num > INT_MAX)
			error_exit();
		num = (int)tmp_num;
		new = create_node(num);
		append_node(&stack_a, new);
		i++;
	}
	check_duplicate(stack_a);
	print_stack(stack_a, "A");
	if (stack_size(stack_a) == 3)
		sort_three(&stack_a);
	print_stack(stack_a, "A");
	free_stack(stack_a);
	return (0);
}
