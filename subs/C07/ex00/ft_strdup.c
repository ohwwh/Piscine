/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:09:58 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 19:42:39 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (src[i] != 0)
		i ++;
	ret = (char *)malloc((i + 1) * sizeof(char));
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
