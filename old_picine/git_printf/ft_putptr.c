/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:09:05 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/12 22:19:40 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_putptr_recursive(unsigned long long ptr, char *base)
{
	int	count;
	int	ret;

	count = 0;
	if (ptr >= 16)
	{
		ret = ft_putptr_recursive(ptr / 16, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = write(1, &base[ptr % 16], 1);
	if (ret == -1)
		return (-1);
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	ret = ft_putptr_recursive((unsigned long long)ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
