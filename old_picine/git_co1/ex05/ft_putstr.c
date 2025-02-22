/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:13:20 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:25 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		write(1, &str[a], 1);
		a++;
	}
}

// int	main(void)
// {
// 	char	*a;

// 	a = "aaaaaaaa";
// 	ft_putstr(a);
// 	return (0);
// }
