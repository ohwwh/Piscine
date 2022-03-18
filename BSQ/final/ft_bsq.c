/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:36:34 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 02:30:41 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_fill_imap(int **map, t_map_info *info)
{
	int	row;
	int col;
	int	bsq;

	row = 1;
	while (row < info->row)
	{
		col = 1;
		while (col < info->col)
		{
			bsq = map[row - 1][col - 1];
			if (bsq > map[row - 1][col])
				bsq = map[row - 1][col];
			if (bsq > map[row][col - 1])
				bsq = map[row][col - 1];
			if (map[row][col])
				map[row][col] = bsq + 1;
			col++;
		}
		row++;
	}
}

void	ft_find_bsq(int **map, t_map_info *info)
{
	int	row;
	int col;
	int	bsq;

	row = 0;
	bsq = 0;
	while (row < info->row)
	{
		col = 0;
		while (col < info->col)
		{
			if (bsq < map[row][col])
				bsq = map[row][col];
			col++;
		}
		row++;
	}
	info->bsq_size = bsq;
}

void	ft_find_first_bsq(int **map, t_map_info *info)
{
	int	row;
	int col;

	row = 0;
	while (row < info->row)
	{
		col = 0;
		while (col < info->col)
		{
			if (map[row][col] == info->bsq_size)
			{
				info->bsq_row = row;
				info->bsq_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	ft_fill_cmap(char **map, t_map_info *info)
{
	int row;
	int col;
	
	row = info->bsq_row - (info->bsq_size - 1);
	while (row <= info->bsq_row)
	{
		col = info->bsq_col - (info->bsq_size - 1);
		while (col <= info->bsq_col)
		{
			if (map[row][col] == info->empty)
			map[row][col] = info->full;
			col++;
		}
		row++;
	}
}