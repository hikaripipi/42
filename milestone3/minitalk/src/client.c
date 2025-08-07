/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:01:50 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/07 18:04:06 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*char_to_binary(char c)
{
	char	*binary;
	int		ascii_value;
	int		i;

	ascii_value = (int)c;
	binary = ft_calloc(9, sizeof(char));
	if (!binary)
		return (NULL);
	i = 7;
	while (i >= 0)
	{
		binary[i] = (ascii_value % 2) + '0';
		ascii_value = ascii_value / 2;
		i--;
	}
	binary[8] = '\0';
	return (binary);
}

void	send_signal_with_check(int pid, int signal, char *bmassage)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("Error: Failed to send signal to PID %d\n", pid);
		free(bmassage);
		exit(1);
	}
}

void	send_char(char c, int pid)
{
	char	*bmassage;
	int		count;

	bmassage = char_to_binary(c);
	if (!bmassage)
		exit(1);
	count = 0;
	while (count < 8)
	{
		if (bmassage[count] == '0')
			send_signal_with_check(pid, SIGUSR1, bmassage);
		else
			send_signal_with_check(pid, SIGUSR2, bmassage);
		usleep(60);
		count++;
	}
	free(bmassage);
}

void	send_massage(int pid, char *massage)
{
	int	i;

	i = 0;
	while (massage[i] != '\0')
	{
		send_char(massage[i], pid);
		i++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	print_timestamp();
	ft_printf("Client: Sending message: %s\n", argv[2]);
	send_massage(server_pid, argv[2]);
	return (0);
}
