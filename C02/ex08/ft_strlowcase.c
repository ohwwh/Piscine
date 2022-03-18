/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:17:48 by hoh               #+#    #+#             */
/*   Updated: 2021/10/19 10:41:10 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char *origin;

	origin = str;
	while (*str != '\0')
	{	
		if (64 < *str && *str < 91)
		{
			*str += 32;
		}
		str ++;
	}
	return (origin);
}

int	main(void)
{
	char str[6] = "Hello";
	ft_strlowcase(str);
	printf("%s", str);
}

