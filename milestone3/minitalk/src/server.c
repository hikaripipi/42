/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:01:28 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/15 22:38:16 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static t_server_data	g_server;

static void	flush_buffer(void)
{
	if (g_server.buffer_pos > 0)
	{
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
		push_char_to_buffer(g_server.current_char);
	g_server.current_char = 0;
	g_server.bit_count = 0;
}

static void	handler(int sig)
{
	g_server.current_char = g_server.current_char << 1;
	if (sig == SIGUSR2)
		g_server.current_char |= 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
		on_byte_completed();
}

int	main(void)
{
	struct sigaction	sa;

	ft_bzero(&g_server, sizeof(g_server));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Error: Failed to set signal handlers\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error: Failed to set signal handlers\n"), 1);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
