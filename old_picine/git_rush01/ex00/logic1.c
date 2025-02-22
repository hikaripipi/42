/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysasai <ysasai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 01:17:19 by hshinaga          #+#    #+#             */
/*   Updated: 2024/08/18 02:11:49 by ysasai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_height(int grid[4][4], int index, int dir, int j)
{
	if (dir == 0)
		return (grid[j][index]);
	else if (dir == 1)
		return (grid[3 - j][index]);
	else if (dir == 2)
		return (grid[index][j]);
	else
		return (grid[index][3 - j]);
}

int	check_visibility(int grid[4][4], int index, int dir)
{
	int	j;
	int	visible;
	int	max;
	int	height;

	j = 0;
	visible = 0;
	max = 0;
	while (j < 4)
	{
		height = get_height(grid, index, dir, j);
		if (height > max)
		{
			max = height;
			visible++;
		}
		j++;
	}
	return (visible);
}

int	is_valid(int grid[4][4], int *views)
{
	int	i;
	int	dir;
	int	visible;

	i = 0;
	while (i < 16)
	{
		dir = i / 4;
		visible = check_visibility(grid, i % 4, dir);
		if (visible != views[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_safe(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
