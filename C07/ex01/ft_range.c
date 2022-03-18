/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:19:49 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 19:43:03 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	if (ret != 0)
	{
		while (min < max)
		{
			ret[i] = min;
			i ++;
			min ++;
		}
		return (ret);
	}
	return (0);
}
