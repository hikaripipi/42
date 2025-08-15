/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:29 by hshinaga          #+#    #+#             */
/*   Updated: 2025/05/12 01:32:19 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

/* ========== Basic - Utilities ========== */
char				**ft_split(char const *s, char c);
int					is_sorted(t_node *stack);
size_t				ft_strlen(const char *str);

/* ========== Init & Stack ========== */
t_node				*create_node(int value);
void				append_node(t_node **stack, t_node *new);
void				parse_args(char **argv, t_node **stack_a);
void				parse_tokens(char **tokens, t_node **stack_a);
void				free_stack(t_node *stack);
int					stack_size(t_node *stack);

/* ========== Sort - Dispatch ========== */
void				sort_dispatch(t_node **a, t_node **b, int size);

/* ========== Sort - Small ========== */
void				sort_two(t_node **stack);
void				sort_three(t_node **stack);
void				sort_four(t_node **a, t_node **b);
void				sort_five(t_node **a, t_node **b);

/* ========== Sort - Large & Chunks ========== */
void				sort_large(t_node **a, t_node **b, int chunk_count);
void				push_chunk(t_node **a, t_node **b, int low, int high);
void				restore_stack(t_node **a, t_node **b);
void				move_to_top(t_node **stack, int index, char name);
int					get_position_of_closest_in_chunk(t_node *stack, int lower,
						int upper);

/* ========== Sort - Index Utilities ========== */
void				assign_indices(t_node *stack);
int					find_min_index(t_node *stack);
int					find_max_index(t_node *stack);
int					get_node_position(t_node *stack, int target_index);
int					is_in_chunk(int index, int lower, int upper);
int					get_chunk_threshold(int size, int chunks, int i);
int					count_elements_in_chunk(t_node *a, int l, int u);

/* ========== Operations ========== */
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

/* ========== Core Operations (Internal) ========== */
void				swap(t_node **stack);
void				push(t_node **from, t_node **to);
void				rotate(t_node **stack);
void				reverse_rotate(t_node **stack);

/* ========== Error & Utils ========== */
void				error_exit(void);
int					is_valid_integer(char *str);
void				check_duplicate(t_node *stack);
int					ft_isdigit(int c);
long				ft_atol(const char *str);

#endif
