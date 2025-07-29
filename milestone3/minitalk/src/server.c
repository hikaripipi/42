/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:54 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/29 19:54:47 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "Hi\n", 13);
}

int	main(void)
{
	while (1)
	{
		signal(SIGINT, handler);
		ft_printf("Server PID: %d\n", getpid());
		sleep(1);
	}
	return (0);
}