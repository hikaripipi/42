/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:54:03 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 22:58:40 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"

void	skip_to_word(char **dict)
{
	while (**dict && **dict != ':')
		(*dict)++;
	if (**dict == ':')
		(*dict)++;
	while (**dict == ' ')
		(*dict)++;
}

void	extract_word(char **dict, char *word)
{
	int	i;

	i = 0;
	while (**dict && **dict != '\n' && **dict != ' ')
	{
		word[i] = **dict;
		i++;
		(*dict)++;
	}
	word[i] = '\0';
}

void	skip_to_next_line(char **dict)
{
	while (**dict && **dict != '\n')
		(*dict)++;
	if (**dict)
		(*dict)++;
}
