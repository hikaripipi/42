/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:07:00 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/26 22:13:07 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include <unistd.h>

void	handle_large_numbers(unsigned long long *number,
		unsigned long long divisor, char *text, char *dictionary)
{
	if (*number >= divisor)
	{
		convert_number_to_words(*number / divisor, dictionary);
		ft_putstr(text);
		*number %= divisor;
		if (*number > 0)
			write(1, " ", 1);
	}
}

void	process_large_number(unsigned long long *number, char *dictionary,
		unsigned long long divisor, char *name)
{
	handle_large_numbers(number, divisor, name, dictionary);
}

void	convert_large_numbers(unsigned long long *number, char *dictionary)
{
	process_large_number(number, dictionary, 1000000000000000000ULL,
		" quintillion");
	process_large_number(number, dictionary, 1000000000000ULL, " trillion");
	process_large_number(number, dictionary, 1000000000ULL, " billion");
	process_large_number(number, dictionary, 1000000ULL, " million");
	process_large_number(number, dictionary, 1000ULL, " thousand");
}

void	convert_number_to_words(unsigned long long number, char *dictionary)
{
	char	word[10000];

	convert_large_numbers(&number, dictionary);
	if (number >= 100)
	{
		if (find_word(dictionary, number / 100, word))
			ft_putstr(word);
		ft_putstr(" hundred");
		number %= 100;
		if (number > 0)
			write(1, " ", 1);
	}
	if (number >= 20)
	{
		if (find_word(dictionary, number / 10 * 10, word))
			ft_putstr(word);
		number %= 10;
		if (number > 0)
			write(1, "-", 1);
	}
	if (number > 0 && find_word(dictionary, number, word))
		ft_putstr(word);
}

int	find_word(char *dictionary, unsigned long long number, char *word)
{
	unsigned long long	num;

	while (*dictionary)
	{
		num = ft_atoi(dictionary);
		if (num == number)
		{
			skip_to_word(&dictionary);
			extract_word(&dictionary, word);
			return (1);
		}
		skip_to_next_line(&dictionary);
	}
	return (0);
}
