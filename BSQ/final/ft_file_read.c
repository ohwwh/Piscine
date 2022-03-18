/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:05:15 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 12:55:58 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_read.h"

int	ft_scan_count(const char *path, int *info_count, int *map_count)
{
	int		fd;
	char	buffer[1];

	fd = ft_file_open(path);
	if (fd < 0)
		return (-1);
	while (read(fd, buffer, 1) > 0)
	{
		(*info_count)++;
		if (*buffer == '\n')
			break ;
	}
	while (read(fd, buffer, 1) > 0)
		(*map_count)++;
	ft_file_close(fd);
	return (0);
}

char	*ft_store_info_str(const char *path, int info_count)
{
	int		fd;
	char	buffer[1];
	char	*info_str;

	fd = ft_file_open(path);
	if (fd < 0)
		return (0);
	info_str = (char *)malloc((info_count + 1) * sizeof(char));
	if (!info_str)
		return (0);
	*info_str = '\0';
	while (read(fd, buffer, 1) > 0)
	{
		if (*buffer == '\n')
			break ;
		ft_strncat(info_str, buffer, 1);
	}
	ft_file_close(fd);
	return (info_str);
}

char	*ft_store_map_str(const char *path, int map_count)
{
	int		fd;
	char	buffer[1];
	char	*map_str;

	fd = ft_file_open(path);
	if (fd < 0)
		return (0);
	map_str = (char *)malloc((map_count + 1) * sizeof(char));
	if (!map_str)
		return (0);
	*map_str = '\0';
	while (read(fd, buffer, 1) > 0)
	{
		if (*buffer == '\n')
			break ;
	}
	while (read(fd, buffer, 1) > 0)
		ft_strncat(map_str, buffer, 1);
	ft_file_close(fd);
	return (map_str);
}
