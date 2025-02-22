/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:07:19 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/12 22:07:26 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_format_handler(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (specifier == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (specifier == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
