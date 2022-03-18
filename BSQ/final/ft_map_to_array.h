/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_array.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:42:43 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 01:19:35 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_TO_ARRAY_H
# define FT_MAP_TO_ARRAY_H

# include <stdlib.h>
# include "ft_file_info.h"
# include "ft_split.h"
# include "ft_map.h"
# include "ft_string.h"
# include "ft_print.h"
# include "ft_free.h"

char	**ft_create_map(char *orig, t_map_info *info);
int		**ft_init_int_map(char **orig, t_map_info *info);
int		ft_write_int_map(char **cmap, int **imap, t_map_info *info);
int		ft_count_row_col(char **map, t_map_info *info);

#endif