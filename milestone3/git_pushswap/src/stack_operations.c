/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:56 by hshinaga          #+#    #+#             */
/*   Updated: 2025/04/30 19:26:45 by hshinaga         ###   ########.fr       */
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

//要確認from to
void push(t_node **from, t_node **to)
{
    t_node *temp;

    if (!from || !(*from))
        return;

    temp = *from;
    *from = (*from)->next;

    temp->next = *to;
    *to = temp;
}

void pa(t_node **a, t_node **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}

void rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

    first = *stack;
    last = *stack;
    while(last->next)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void ra(t_node **a)
{
    rotate(a);
    write(1,"ra\n", 3);
}

void rb(t_node **b)
{
    rotate(b);
    write(1,"rb\n", 3);
}
void rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    write(1,"rr\n", 3);
}

void reverse_rotate(t_node **stack)
{
	t_node	*last;
    t_node *prev;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

    prev = *stack;
    while(prev->next && prev->next->next)
        prev = prev->next;
        
    last = prev->next;
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}
void rra(t_node **a)
{
    reverse_rotate(a);
    write(1,"rra\n", 4);
}
void rrb(t_node **b)
{
    reverse_rotate(b);
    write(1,"rrb\n", 4);
}
void rrr(t_node **a, t_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1,"rrr\n", 4);
}