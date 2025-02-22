/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:54:31 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 23:12:41 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10000

typedef struct s_large_number
{
	unsigned long long		divisor;
	char					*name;
}							t_large_number;

// 'extern' キーワードを使用して、配列が他の場所で定義されることを示す
extern const t_large_number	g_large_numbers[];

// main.c
int							main(int argc, char **argv);
int							process_arguments(int argc, char **argv,
								char **dict_filename);
char						*read_dictionary(const char *filename);
int							handle_file_error(int fd, char *buffer);
void						ft_putstr(char *str);

// convert.c
void						convert_number_to_words(unsigned long long number,
								char *dictionary);
void						convert_large_numbers(unsigned long long *number,
								char *dictionary);
void						handle_large_numbers(unsigned long long *number,
								unsigned long long divisor, char *text,
								char *dictionary);
int							find_word(char *dictionary,
								unsigned long long number, char *word);

// utils.c
int							ft_strlen(const char *str);
int							is_greater_than_max(const char *str);
unsigned long long			ft_atoi(const char *str);
int							is_valid_number(const char *str);

// dict_utils.c
void						skip_to_word(char **dict);
void						extract_word(char **dict, char *word);
void						skip_to_next_line(char **dict);

#endif