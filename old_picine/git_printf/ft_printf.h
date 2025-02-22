/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:24:57 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/08 19:25:23 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(long long n, char *base);
int	ft_putptr(void *ptr);

#endif