/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:01:28 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/07 17:40:26 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static t_server_data	g_server;

void	handler1(int sig)
{
	(void)sig;
	g_server.current_char = g_server.current_char << 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		if (g_server.char_count < 999)
		{
			g_server.message[g_server.char_count] = g_server.current_char;
			g_server.char_count++;
		}
		if (g_server.current_char == '\0')
		{
			ft_printf("Server: Received: %s\n", g_server.message);
			g_server.char_count = 0;
		}
		g_server.current_char = 0;
		g_server.bit_count = 0;
	}
}

void	handler2(int sig)
{
	(void)sig;
	g_server.current_char = (g_server.current_char << 1) | 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		if (g_server.char_count < 999)
		{
			g_server.message[g_server.char_count] = g_server.current_char;
			g_server.char_count++;
		}
		if (g_server.current_char == '\0')
		{
			ft_printf("Server: Received: %s\n", g_server.message);
			g_server.char_count = 0;
		}
		g_server.current_char = 0;
		g_server.bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

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
