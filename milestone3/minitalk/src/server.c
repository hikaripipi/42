/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:01:28 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 22:03:14 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static t_server_data	g_server;

static void	flush_buffer(void)
{
	if (g_server.buffer_pos > 0)
	{
		/* async-signal-safe output */
		write(1, g_server.buffer, g_server.buffer_pos);
		g_server.buffer_pos = 0;
	}
}

static void	push_char_to_buffer(char c)
{
	g_server.buffer[g_server.buffer_pos++] = c;
	if (g_server.buffer_pos == CHUNK_SIZE)
		flush_buffer();
}

static void	on_byte_completed(void)
{
	if (g_server.current_char == '\0')
	{
		flush_buffer();
		write(1, "\n", 1);
	}
	else
	{
		push_char_to_buffer(g_server.current_char);
	}
	g_server.current_char = 0;
	g_server.bit_count = 0;
}

void	handler1(int sig)
{
	(void)sig;
	g_server.current_char = g_server.current_char << 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
		on_byte_completed();
}

void	handler2(int sig)
{
	(void)sig;
	g_server.current_char = (g_server.current_char << 1) | 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
		on_byte_completed();
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	g_server.current_char = 0;
	g_server.bit_count = 0;
	g_server.buffer_pos = 0;
	g_server.message_started = 0;
	g_server.buffer[0] = '\0';
	sa1.sa_handler = handler1;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = 0;
	sa2.sa_handler = handler2;
	sigemptyset(&sa2.sa_mask);
	sa2.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa1, NULL) == -1 || sigaction(SIGUSR2, &sa2,
			NULL) == -1)
	{
		ft_printf("Error: Failed to set signal handlers\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
