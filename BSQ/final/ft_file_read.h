/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:05:15 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/25 22:06:17 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_READ_H
# define FT_FILE_READ_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_string.h"
# include "ft_file_oc.h"

int		ft_scan_count(const char *path, int *info_count, int *map_count);
char	*ft_store_info_str(const char *path, int info_count);
char	*ft_store_map_str(const char *path, int map_count);

#endif
