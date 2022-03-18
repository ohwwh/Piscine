/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:09:55 by ohw               #+#    #+#             */
/*   Updated: 2021/10/26 21:23:56 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len ++;
	return (len);
}

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i ++;
	t = i;
	while (i + 1 < size && src[j] != '\0')
	{
		dest[i] = src[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	while (src[j] != '\0')
		j ++;
	if (t >= size)
		return (j + size);
	else
		return (t + j);
}

int	getsize(int size, char *strs, char *sep)
{
	int	len;
	int	k;
	int	bsize;

	if (size == 0)
		return (1);
	if (size < 0)
		return (-1);
	bsize = 0;
	k = 1;
	while (k <= size)
	{
		len = ft_strlen(strs);
		bsize += len + 1;
		if (k != size)
			strs += (len + 1);
		k ++;
	}
	return (bsize + (ft_strlen(sep) * (size - 1)));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		bsize;
	int		k;

	k = 1;
	bsize = getsize(size, *strs, sep);
	if (bsize < 0)
		return (0);
	ret = (char *)malloc(bsize);
	if (ret != 0)
	{
		while (k <= size)
		{
			ft_strlcat(ret, strs[k - 1], bsize);
			if (k != size)
				ft_strlcat(ret, sep, bsize);
			k ++;
		}
		return (ret);
	}
	return (0);
}
