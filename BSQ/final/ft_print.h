/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:59:48 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 00:50:47 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <unistd.h>
# include "ft_map.h"

void	ft_print_cmap(t_map_info *info, char **cmap);
int		ft_print_maperr(void);
void	*ft_print_maperr_vp(void);

#endif