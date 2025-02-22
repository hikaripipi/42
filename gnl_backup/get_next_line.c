/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:43:20 by hshinaga          #+#    #+#             */
/*   Updated: 2025/02/06 19:41:58 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *extract_line(char **saved)
{
    char    *line;
    char    *temp;
    char    *newline_pos;
    size_t  len;

    if (!*saved || !**saved)
        return (NULL);
    newline_pos = ft_strchr(*saved, '\n');
    if (newline_pos)
    {
        len = newline_pos - *saved + 1;
        line = (char *)malloc(sizeof(char) * (len + 1));
        if (!line)
            return (NULL);
        ft_strlcpy(line, *saved, len + 1);
        line[len - 1] = '\n';
        line[len] = '\0';
        temp = ft_strdup(newline_pos + 1);
        free(*saved);
        *saved = temp;
    }
    else
    {
        line = ft_strdup(*saved);
        free(*saved);
        *saved = NULL;
    }
    return (line);
}

static char *read_to_saved(int fd, char **saved)
{
    char    *buffer;
    char    *temp;
    ssize_t read_bytes;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    read_bytes = 1;
    while (read_bytes > 0 && (!*saved || !ft_strchr(*saved, '\n')))
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[read_bytes] = '\0';
        temp = ft_strjoin(*saved ? *saved : "", buffer);
        free(*saved);
        *saved = temp;
    }
    free(buffer);
    return (*saved);
}

char *get_next_line(int fd)
{
    static char *saved;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!saved || !ft_strchr(saved, '\n'))
    {
        if (!read_to_saved(fd, &saved))
        {
            if (saved)
            {
                // 最後の行を処理後、savedを完全に解放
                line = extract_line(&saved);
                if (!line && saved)
                {
                    free(saved);
                    saved = NULL;
                }
                return (line);
            }
            return (NULL);
        }
    }
    return (extract_line(&saved));
}
