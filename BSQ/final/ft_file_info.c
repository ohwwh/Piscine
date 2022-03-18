/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:07:05 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 11:57:38 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_info.h"

t_map_info	*ft_create_info(char *info)
{
	int 		length;
	t_map_info	*out;

	length = ft_strlen(info);
	if (length < 4)
		return (ft_print_maperr_vp());
	out = (t_map_info *)malloc(sizeof(t_map_info));
	if (!out)
		return (NULL);
	out->empty = info[length - 3];
	out->obs = info[length - 2];
	out->full = info[length - 1];
	info[length - 3] = '\0';
	out->row = ft_atoi(info);
	free(info);
	if (ft_check_dup_char(out) || out->row == 0)
	{
		free(out);
		return (ft_print_maperr_vp());
	}
	return (out);
}

int	ft_check_dup_char(t_map_info *info)
{
	if (info->empty == info->full)
		return (1);
	if (info->full == info->obs)
		return (1);
	if (info->obs == info->empty)
		return (1);
	return (0);
}

int	ft_check_cmap(char *map_str, t_map_info *info)
{
	while (*map_str)
	{
		if (*map_str == info->empty)
		{
			map_str++;
			continue ;
		}
		if (*map_str == info->obs)
		{
			map_str++;
			continue ;
		}
		return (0);
	}
	return (1);
}
