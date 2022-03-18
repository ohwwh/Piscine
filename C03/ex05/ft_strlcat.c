/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:52:56 by ohw               #+#    #+#             */
/*   Updated: 2021/10/19 16:45:39 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	t;

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

int	main(void)
{
	char str1[13] = "Hello";
	char str2[6] = "World";
	printf("%d\n", ft_strlcat(str1, str2, 3));
	printf("%s\n", str1);
}
