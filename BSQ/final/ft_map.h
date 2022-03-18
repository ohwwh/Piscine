/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:53:01 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 20:26:25 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

struct	s_map_info
{
	int		row;
	int		col;
	int		bsq_row;
	int		bsq_col;
	int		bsq_size;
	char	empty;
	char	obs;
	char	full;
};

typedef struct s_map_info	t_map_info;

#endif
