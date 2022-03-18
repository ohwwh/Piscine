/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:07:42 by hoh               #+#    #+#             */
/*   Updated: 2021/10/28 17:11:07 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*ret;
	int	i;	

	i = 0;
	ret = (int*)malloc(sizeof(int) * length);
	if (ret)
	{
		while (i < length)
		{
			ret[i] = f(tab[i]);
			i ++;
		}
	}
	return (ret);
}
