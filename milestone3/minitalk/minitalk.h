/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:59:16 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 22:38:16 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "include/ft_printf/ft_printf.h"
# include "include/libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define CHUNK_SIZE 512

typedef struct s_server_data
{
	char	current_char;
	int		bit_count;
	char	buffer[CHUNK_SIZE + 1];
	int		buffer_pos;
}			t_server_data;

void		print_timestamp(void);

#endif
