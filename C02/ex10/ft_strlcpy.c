/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:51:08 by hoh               #+#    #+#             */
/*   Updated: 2021/10/19 17:41:40 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	if (size != 0)
		dest[i] = '\0';
	while (src[i] != '\0')
		i ++;
	return (i);
}

int	main(void)
{
	char dest[12] = "HelloWorld!";
	char src[8] = "sourcex";
	
	printf("%d\n", ft_strlcpy(dest, src, 5));
	for (int i = 0; i < 12; i ++)
		printf("%c", dest[i]);
}
