/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:34:54 by ohw               #+#    #+#             */
/*   Updated: 2021/10/19 16:26:15 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*tmp;

	tmp = dest;
	i = 1;
	while (*dest != '\0')
		dest ++;
	while (i <= nb && *src != '\0')
	{
		*dest = *src;
		i ++;
		dest ++;
		src ++;
	}
	*dest = '\0';
	return (tmp);
}

int	main(void)
{
	char dest[20] = "Hello";
	char src[6] = "World";

	printf("%s", ft_strncat(dest, src, 2));
}
