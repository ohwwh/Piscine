/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:11:54 by ohw               #+#    #+#             */
/*   Updated: 2021/10/26 17:19:49 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (src[i] != 0)
		i ++;
	ret = (char *)malloc((i + 1) * 1);
	while (ret != 0)
	{
		i = 0;
		while (src[i] != 0)
		{
			ret[i] = src[i];
			i ++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len ++;
	return (len);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;

	i = 0;
	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret != 0)
	{
		while (i < ac)
		{
			ret[i].size = ft_strlen(av[i]);
			ret[i].str = av[i];
			ret[i].copy = ft_strdup(av[i]);
			i ++;
		}
		ret[i].size = 0;
		ret[i].str = 0;
		ret[i].copy = 0;
		return (ret);
	}
	return (0);
}
