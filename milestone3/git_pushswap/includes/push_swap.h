/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:29 by hshinaga          #+#    #+#             */
/*   Updated: 2025/05/10 21:33:23 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> // for INT_MIN / INT_MAX
# include <stdlib.h>
# include <unistd.h>

// --- 構造体定義 ---
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

//         Error Handling

void				error_exit(void);
int					is_valid_integer(char *str);
void				check_duplicate(t_node *stack);
long				ft_atol(const char *str);

//          Init / Parse

t_node				*create_node(int value);
void				append_node(t_node **stack, t_node *new);
int					stack_size(t_node *stack);
void				free_stack(t_node *stack);
void				assign_indices(t_node *stack);

//         Sort - Small

void				sort_two(t_node **stack);
void				sort_three(t_node **stack);
void				sort_four(t_node **a, t_node **b);
void				sort_five(t_node **a, t_node **b);

//         Sort - Large

void				sort_large(t_node **a, t_node **b, int chunk_count);
void				push_chunk(t_node **a, t_node **b, int lower, int upper);
void				restore_stack(t_node **a, t_node **b);

//       Sort - Utilities

int					find_min_index(t_node *stack);
int					find_max_index(t_node *stack);
int					get_chunk_threshold(int total_size, int chunk_count,
						int chunk_index);
int					is_in_chunk(int index, int lower, int upper);
int					count_elements_in_chunk(t_node *a, int lower, int upper);
int					get_node_position(t_node *stack, int target_index);
void				move_to_top(t_node **stack, int index, char stack_name);

//       Operations - Core

void				swap(t_node **stack);
void				push(t_node **src, t_node **dest);
void				rotate(t_node **stack);
void				reverse_rotate(t_node **stack);

//    Operations - Interface

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

#endif
