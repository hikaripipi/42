/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:19:28 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/20 02:08:27 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_put_address(unsigned long addr)
{
	char	*hex;
	int		i;
	char	address[16];

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		address[15 - i] = hex[addr % 16];
		addr /= 16;
		i++;
	}
	i = 0;
	while (i < 16)
		ft_putchar(address[i++]);
}

void	ft_print_line(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_putnbr_hex(addr[i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_put_address((unsigned long)(ptr + i));
		ft_putchar(':');
		ft_putchar(' ');
		if (size - i < 16)
			ft_print_line(ptr + i, size - i);
		else
			ft_print_line(ptr + i, 16);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

// int	main(void)
// {
// 	char data[] = "Bonjour les aminches\t\n\tc est fou\t"
// 					"tout ce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
// 	ft_print_memory(data, sizeof(data));
// 	return (0);
// }
