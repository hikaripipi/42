/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:30 by hshinaga          #+#    #+#             */
/*   Updated: 2025/02/06 19:41:13 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s1);  // 追加
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif