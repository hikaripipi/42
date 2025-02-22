/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:43:20 by hshinaga          #+#    #+#             */
/*   Updated: 2025/02/12 21:36:47 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_and_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	read_size;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(stash, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = tmp;
	}
	free(buf);
	if (read_size <= 0 && !stash)
		return (NULL);
	return (stash);
}

static char	*ft_extract_line(char *stash)
{
	size_t	i;
	char	*line;
	size_t	len;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = i;
	if (stash[i] == '\n')
		len++;
	line = ft_strdup(stash);
	if (line)
		line[len] = '\0';
	return (line);
}

static char	*ft_trim_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_trim_stash(stash);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
