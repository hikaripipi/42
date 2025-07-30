/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:56:57 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/30 21:35:28 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: %s need correct input\n", argv[0]);
		return (1);
	}
	kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
