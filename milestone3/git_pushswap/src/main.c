/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:43 by hshinaga          #+#    #+#             */
/*   Updated: 2025/04/30 19:44:48 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// スタックの中身を出力する補助関数
void print_stack(t_node *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main(void)
{
    // スタックA: 1 → 2 → 3
    t_node *a = create_node(1);
    a->next = create_node(2);
    a->next->next = create_node(3);

    // スタックB: 4 → 5 → 6
    t_node *b = create_node(4);
    b->next = create_node(5);
    b->next->next = create_node(6);

    printf("Before:\n");
    print_stack(a, "A");
    print_stack(b, "B");

    // ========================
    // 全スタック操作を1回ずつ実行
    // ========================

    sa(&a);
    sb(&b);
    ss(&a, &b);
    pa(&a, &b);
    pb(&a, &b);
    ra(&a);
    rb(&b);
    rr(&a, &b);
    rra(&a);
    rrb(&b);
    rrr(&a, &b);

    printf("After:\n");
    print_stack(a, "A");
    print_stack(b, "B");

    free_stack(a);
    free_stack(b);
    return 0;
}


