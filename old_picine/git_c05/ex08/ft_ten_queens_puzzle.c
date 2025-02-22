/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:10:36 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/25 00:41:43 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_solution(int board[10])
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int a, int b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

int	ft_is_safe(int board[10], int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || ft_abs(board[i], row) == ft_abs(i, col))
			return (0);
		i++;
	}
	return (1);
}

void	ft_solve(int board[10], int col, int *count)
{
	int	row;

	if (col == 10)
	{
		ft_print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (ft_is_safe(board, row, col))
		{
			board[col] = row;
			ft_solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	ft_solve(board, 0, &count);
	return (count);
}

// int	main(void)
// {
// 	int total_solutions;

// 	// ft_ten_queens_puzzle 関数を呼び出し、解の総数を取得
// 	total_solutions = ft_ten_queens_puzzle();

// 	// 解の総数を表示
// 	printf("Total number of solutions: %d\n", total_solutions);

// 	return (0);
// }