/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:53:55 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 22:56:47 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	handle_file_error(int fd, char *buffer)
{
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (!buffer)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

char	*read_dictionary(const char *filename)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	buffer = malloc(BUFFER_SIZE);
	if (!handle_file_error(fd, buffer))
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		write(1, "Dict Error\n", 11);
		return (0);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	process_arguments(int argc, char **argv, char **dict_filename)
{
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
		*dict_filename = argv[1];
	else
		*dict_filename = "numbers.dict";
	if (!is_valid_number(argv[argc - 1]) || is_greater_than_max(argv[argc - 1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char				*dictionary;
	unsigned long long	number;
	char				*dict_filename;

	if (!process_arguments(argc, argv, &dict_filename))
		return (0);
	dictionary = read_dictionary(dict_filename);
	if (!dictionary)
		return (0);
	number = ft_atoi(argv[argc - 1]);
	if (number == 0)
		write(1, "zero\n", 5);
	else
	{
		convert_number_to_words(number, dictionary);
		write(1, "\n", 1);
	}
	free(dictionary);
	return (0);
}
