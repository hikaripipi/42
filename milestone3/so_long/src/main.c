/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:45:09 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/22 19:05:19 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("Hello, so_long!\n");
	printf("Arguments: %d\n", argc);
	if (argc > 1)
		printf("Map file: %s\n", argv[1]);
	return (0);
}