/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:09 by hshinaga          #+#    #+#             */
/*   Updated: 2024/11/06 00:04:02 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src_str)
{
	char	*new_str;
	size_t	str_len;

	str_len = ft_strlen(src_str);
	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, src_str, str_len + 1);
	return (new_str);
}
