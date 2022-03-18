/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:07:05 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 00:47:35 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_INFO_H
# define FT_FILE_INFO_H

# include <stdlib.h>
# include "ft_string.h"
# include "ft_map.h"
# include "ft_atoi.h"
# include "ft_print.h"

t_map_info	*ft_create_info(char *info);
int	ft_check_dup_char(t_map_info *info);
int	ft_check_cmap(char *map_str, t_map_info *info);

#endif