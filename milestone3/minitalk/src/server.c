/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:54 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/30 21:34:56 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int num)
{
	(void)num;
	ft_printf("got signal\n");
}

int	main(void)
{
	while (1)
	{
		signal(SIGUSR1, handler);
		ft_printf("Server PID: %d\n", getpid());
		sleep(1);
	}
	return (0);
}