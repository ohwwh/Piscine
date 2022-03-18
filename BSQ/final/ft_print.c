/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:59:48 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 12:08:12 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_print_cmap(t_map_info *info, char **cmap)
{
	int	i;
	int j;

	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			write(1, &cmap[i][j], 1);
			j++;
		}
		write(1, &"\n", 1);
		i++;
	}
}

int	ft_print_maperr(void)
{
	write(1, "map error\n", 10);
	return (-1);
}

void	*ft_print_maperr_vp(void)
{
	write(1, "map error\n", 10);
	return (NULL);
}
