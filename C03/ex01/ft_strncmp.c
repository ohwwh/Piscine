/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:58:51 by ohw               #+#    #+#             */
/*   Updated: 2021/10/19 16:24:18 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{	
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 1;
	while (i <= n && (*s1 != '\0' | *s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (i == n && *s1 == *s2)
			return (0);
		s1 ++;
		s2 ++;
		i ++;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	char str1[6] = "hello";
	char str2[6] = "helx";

	printf("%d", ft_strncmp(str1, str2, 0));
	printf("%d", ft_strncmp(str1, str2, 3));
	printf("%d", ft_strncmp(str1, str2, 7));
}
