/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:29 by hshinaga          #+#    #+#             */
/*   Updated: 2025/05/01 15:15:09 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>  // printf (デバッグ用、後で消すかも)
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, read

// 構造体定義
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// 関数プロトタイプ（これから実装する関数のリスト）
void				error_exit(void);
t_node				*create_node(int value);
void				free_stack(t_node *stack);
void				push(t_node **stack_src, t_node **stack_dest);
void				swap(t_node **stack);
void				rotate(t_node **stack);
void				reverse_rotate(t_node **stack);

// operations
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

// ソートアルゴリズム
void				sort_stack(t_node **stack_a, t_node **stack_b);

// ユーティリティ関数
int					is_sorted(t_node *stack);
int					stack_size(t_node *stack);

// error
int					is_valid_integer(char *str);
void				check_duplicate(t_node *stack);

#endif