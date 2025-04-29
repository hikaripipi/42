/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:29 by hshinaga          #+#    #+#             */
/*   Updated: 2025/04/29 21:42:37 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>  // malloc, free
# include <unistd.h>  // write, read
# include <stdio.h>   // printf (デバッグ用、後で消すかも)

// 構造体定義
typedef struct s_node
{
    int             value;
    struct s_node  *next;
}   t_node;

// 関数プロトタイプ（これから実装する関数のリスト）
void    error_exit(void);
t_node  *create_node(int value);
void    push(t_node **stack_src, t_node **stack_dest);
void    swap(t_node **stack);
void    rotate(t_node **stack);
void    reverse_rotate(t_node **stack);

//operations
void sa(t_node **a);


// ソートアルゴリズム
void    sort_stack(t_node **stack_a, t_node **stack_b);


// ユーティリティ関数
int     is_sorted(t_node *stack);
int     stack_size(t_node *stack);

#endif