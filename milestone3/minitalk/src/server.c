/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:54 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/02 02:15:38 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static char	current_char = 0;
static int	bit_count = 0;
static char	message[1000];
static int	char_count = 0;

void	handler1(int sig)
{
	(void)sig;
	current_char = current_char << 1;
	bit_count++;
	if (bit_count == 8)
	{
		message[char_count] = current_char;
		char_count++;
		if (current_char == '\0')
		{
			ft_printf("Received: %s\n", message);
			char_count = 0;
		}
		current_char = 0;
		bit_count = 0;
	}
}

void	handler2(int sig)
{
	(void)sig;
	current_char = (current_char << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		message[char_count] = current_char;
		char_count++;
		if (current_char == '\0')
		{
			ft_printf("Received: %s\n", message);
			char_count = 0;
		}
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handler1);
	signal(SIGUSR2, handler2);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
