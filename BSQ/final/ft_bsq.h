/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:36:34 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/25 22:30:31 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include "ft_map_to_array.h"
# include "ft_map.h"

void	ft_fill_imap(int **map, t_map_info *info);
void	ft_find_bsq(int **map, t_map_info *info);
void	ft_find_first_bsq(int **map, t_map_info *info);
void	ft_fill_cmap(char **map, t_map_info *info);

#endif