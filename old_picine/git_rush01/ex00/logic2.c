/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysasai <ysasai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 02:09:57 by ysasai            #+#    #+#             */
/*   Updated: 2024/08/18 02:11:49 by ysasai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int grid[4][4], int *views);
int	is_safe(int grid[4][4], int row, int col, int num);

int	solve_skyscraper(int grid[4][4], int *views, int row, int col)
{
	int	num;

	if (row == 3 && col == 4)
		return (is_valid(grid, views));
	if (col == 4)
	{
		row++;
		col = 0;
	}
	if (grid[row][col] != 0)
		return (solve_skyscraper(grid, views, row, col + 1));
	num = 1;
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_skyscraper(grid, views, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
