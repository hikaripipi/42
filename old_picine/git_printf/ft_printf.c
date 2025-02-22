/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:26:44 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/12 22:18:26 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	handle_format(const char *format, va_list args, int *i)
{
	int	ret;

	(*i)++;
	ret = ft_format_handler(format[*i], args);
	if (ret == -1)
		return (-1);
	return (ret);
}

static int	print_char(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			ret = handle_format(format, args, &i);
		else
			ret = print_char(format[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	va_end(args);
	return (count);
}
