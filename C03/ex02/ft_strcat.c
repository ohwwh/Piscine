/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:34:54 by ohw               #+#    #+#             */
/*   Updated: 2021/10/19 16:24:31 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i ++;
	while (*src != '\0')
	{
		dest[i] = *src;
		i ++;
		src ++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char dest[20] = "Hello";
	char src[6] = "World";

	printf("%s", ft_strcat(dest, src));
}
