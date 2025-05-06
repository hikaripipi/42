/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:29 by hshinaga          #+#    #+#             */
/*   Updated: 2025/05/06 19:37:27 by hikarimac        ###   ########.fr       */
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
	int				index;
	struct s_node	*next;
}					t_node;

// 関数プロトタイプ（これから実装する関数のリスト）

// error
void				error_exit(void);
int					is_valid_integer(char *str);
void				check_duplicate(t_node *stack);

// ソートアルゴリズム
void				sort_three(t_node **stack);
void				sort_five(t_node **stack_a, t_node **stack_b);
void				push_chunk(t_node **a, t_node **b, int lower, int upper);
void				sort_large(t_node **a, t_node **b, int chunk_count);

// sortユーティリティ関数
int					find_min_index(t_node *stack);
int					find_max_index(t_node *stack);
void				move_to_top(t_node **stack, int index, char stack_name);
void				assign_indices(t_node *stack);
int					get_chunk_threshold(int total_size, int chunk_count,
						int chunk_index);
int					is_in_chunk(int index, int lower, int upper);
int					count_elements_in_chunk(t_node *a, int lower, int upper);
int					get_node_position(t_node *stack, int target_index);

// operations
void				push(t_node **stack_src, t_node **stack_dest);
void				swap(t_node **stack);
void				rotate(t_node **stack);
void				reverse_rotate(t_node **stack);
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

// stackユーティリティ関数
t_node				*create_node(int value);
void				free_stack(t_node *stack);
int					stack_size(t_node *stack);

#endif