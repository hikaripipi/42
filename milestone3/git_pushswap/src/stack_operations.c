/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:56 by hshinaga          #+#    #+#             */
/*   Updated: 2025/04/29 21:38:34 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void sa(t_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

