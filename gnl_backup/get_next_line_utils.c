/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:21:26 by hshinaga          #+#    #+#             */
/*   Updated: 2025/02/06 19:25:36 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

char    *ft_strdup(const char *s1)
{
    char    *str;
    size_t  len;
    size_t  i;

    if (!s1)
        return (NULL);
    len = ft_strlen(s1);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  i;
    size_t  j;
    size_t  s1_len;
    size_t  s2_len;

    if (!s1 && !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!str)
        return (NULL);
    i = -1;
    while (++i < s1_len)
        str[i] = s1[i];
    j = -1;
    while (++j < s2_len)
        str[i + j] = s2[j];
    str[i + j] = '\0';
    return (str);
}
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t  src_len;

    src_len = ft_strlen(src);
    if (dstsize == 0)
        return (src_len);
    i = 0;
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);
}