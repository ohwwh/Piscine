/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_oc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:59:20 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/25 18:50:27 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_oc.h"

int	ft_file_open(const char *path)
{
	return (open(path, O_RDONLY));
}

int	ft_file_close(int fd)
{
	return (close(fd));
}
