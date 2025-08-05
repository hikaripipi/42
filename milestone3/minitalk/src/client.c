/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:57 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/05 14:55:35 by hikarimac        ###   ########.fr       */
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

void	send_char(char c, int pid)
{
	char	*bmassage;
	int		count;

	bmassage = char_to_binary(c);
	count = 0;
	while (count < 8)
	{
		if (bmassage[count] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
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
	send_char('\0', pid); // null終端文字も同じ関数で！
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: %s need correct input\n", argv[0]);
		return (1);
	}
	print_timestamp();
	ft_printf("Client: Sending message: %s\n", argv[2]);
	send_massage(ft_atoi(argv[1]), argv[2]);
	// kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
