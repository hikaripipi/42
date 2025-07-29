/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 07:34:18 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/29 19:35:36 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "include/ft_printf/ft_printf.h"
# include "include/libft/libft.h"
# include <signal.h>    // sigaction, kill, etc
# include <stdio.h>     // optional for debug (not needed in final)
# include <stdlib.h>    // malloc, free
# include <sys/types.h> // pid_t
# include <unistd.h>    // write, usleep

// // ===== ユーティリティ関数 =====
// void	ft_putchar(char c);
// void	ft_putstr(const char *s);
// int		ft_atoi(const char *str);
// int		ft_strlen(const char *str);

// // ===== クライアント側 =====
// void	send_char(pid_t server_pid, char c);
// void	send_str(pid_t server_pid, const char *str);

// // ===== サーバー側 =====
// void	handle_signal(int sig, siginfo_t *info, void *context);

#endif
