/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:00:00 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/26 00:27:39 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include <stdlib.h>
# include "ft_map.h"

void	ft_free_imap(t_map_info *info, int **imap);
void	ft_free_cmap(char **cmap);

#endif