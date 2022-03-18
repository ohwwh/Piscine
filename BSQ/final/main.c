/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:16:32 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 20:45:28 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is_char.h"
#include "ft_file_oc.h"
#include "ft_file_read.h"
#include "ft_file_info.h"
#include "ft_map_to_array.h"
#include "ft_bsq.h"
#include "ft_free.h"
#include "ft_print.h"

int	ft_init(const char *path, t_map_info **info, char ***cmap)
{
	int 	info_count;
	int 	map_count;
	char	*info_str;
	char	*map_str;

	ft_scan_count(path, &info_count, &map_count);
	info_str = ft_store_info_str(path, info_count);
	map_str = ft_store_map_str(path, map_count);
	if (info_str)
	{
		*info = ft_create_info(info_str);
		if (*info == NULL)
			return (-1);
	}
	else
		return (-1);
	if (map_str)
	{
		*cmap = ft_create_map(map_str, *info);
		if (*cmap == NULL)
			return (-2);
	}
	else
		return (-2);
	ft_count_row_col(*cmap, *info);
	return (0);
}

int	ft_process_imap(t_map_info *info, char **cmap)
{
	int	**imap;

	if (info && cmap)
	{
		imap = ft_init_int_map(cmap, info);
		if (imap)
		{
			ft_fill_imap(imap, info);
			ft_find_bsq(imap, info);
			ft_find_first_bsq(imap, info);
			ft_fill_cmap(cmap, info);
			ft_free_imap(info, imap);
			return (0);
		}
	}
	return (-1);
}

int main(int argc, char **argv)
{
	int			index;
	int			free_guard;
	char		*path;
	char		**cmap;
	t_map_info 	*info;

	if (argc >= 2)
	{
		index = 1;
		while (index < argc)
		{
			path = argv[index++];
			free_guard = ft_init(path, &info, &cmap);
			if (free_guard == 0)
			{
				if (!ft_process_imap(info, cmap))
					ft_print_cmap(info, cmap);
				ft_free_cmap(cmap);
			}
			if (free_guard != -1)
				free(info);
		}
	}
	while (1);
	return (0);
}
