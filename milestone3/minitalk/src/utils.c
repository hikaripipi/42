/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:57:01 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/05 14:55:04 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <sys/time.h>
#include <time.h>

static void	print_two_digits(int num)
{
	if (num < 10)
		ft_printf("0%d", num);
	else
		ft_printf("%d", num);
}

static void	print_three_digits(int num)
{
	if (num < 10)
		ft_printf("00%d", num);
	else if (num < 100)
		ft_printf("0%d", num);
	else
		ft_printf("%d", num);
}

void	print_timestamp(void)
{
	struct timeval	tv;
	struct tm		*tm_info;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_printf("Error getting time\n");
		return ;
	}
	tm_info = localtime(&tv.tv_sec);
	if (!tm_info)
	{
		ft_printf("Error converting time\n");
		return ;
	}
	ft_printf("[");
	print_two_digits(tm_info->tm_hour);
	ft_printf(":");
	print_two_digits(tm_info->tm_min);
	ft_printf(":");
	print_two_digits(tm_info->tm_sec);
	ft_printf(".");
	print_three_digits((int)(tv.tv_usec / 1000));
	ft_printf("] ");
}
