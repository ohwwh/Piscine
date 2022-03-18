/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_oc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:00:35 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/23 23:16:58 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_OC_H
# define FT_FILE_OC_H

# include <fcntl.h>
# include <unistd.h>

int	ft_file_open(const char *path);
int	ft_file_close(int fd);

#endif
