/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:42:43 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 02:30:00 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_to_array.h"
#include <stdio.h>

char	**ft_create_map(char *orig, t_map_info *info)
{
	char	**map;
	int		index;

	if (!ft_check_cmap(orig, info))
		map = ft_split(orig, "\n");
	else
	{
		free(orig);
		return (ft_print_maperr_vp());
	}
	free(orig);
	if (!map)
		return (NULL);
	index = 0;
	while (map[index])
		index++;
	if (index != info->row)
		return (ft_print_maperr_vp());
	return (map);
}

int	**ft_init_int_map(char **orig, t_map_info *info)
{
	int	**map;
	int	index;

	map = (int **)malloc(info->row * sizeof(int *));
	if (!map)
		return (NULL);
	index = 0;
	while (index < info->row)
	{
		map[index] = (int *)malloc(info->col * sizeof(int));
		if (!map[index])
			return (NULL);
		index++;
	}
	if (ft_write_int_map(orig, map, info))
	{
		ft_free_imap(info, map);
		return (NULL);
	}
	return (map);
}

int	ft_write_int_map(char **cmap, int **imap, t_map_info *info)
{
	int	row;
	int col;

	row = 0;
	while (cmap[row])
	{
		col = 0;
		while (cmap[row][col])
		{
			if (cmap[row][col] == info->obs)
				imap[row][col] = 0;
			else if (cmap[row][col] == info->empty)
				imap[row][col] = 1;
			else
				return (ft_print_maperr());
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_count_row_col(char **map, t_map_info *info)
{
	int row_check;

	info->col = ft_strlen(map[0]);
	row_check = 0;
	while (map[row_check])
	{
		if (ft_strlen(map[row_check]) != info->col)
			return (ft_print_maperr());
		row_check++;
	}
	if (row_check != info->row)
		return (ft_print_maperr());
	return (0);
}