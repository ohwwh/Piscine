/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:00:00 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 00:30:26 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

void	ft_free_imap(t_map_info *info, int **imap)
{
	int	index;

	index = 0;
	while (index < info->row)
		free(imap[index++]);
	free(imap);
}

void	ft_free_cmap(char **cmap)
{
	int	index;

	index = 0;
	while (cmap[index])
		free(cmap[index++]);
	free(cmap);
}