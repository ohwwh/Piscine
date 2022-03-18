/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:21:37 by hoh               #+#    #+#             */
/*   Updated: 2021/10/26 15:39:57 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i ++;
	}
	return (dest);
}

int	main(void)
{
	char des[11] = "helloworld";
	char src[5]	= "strc";
	for(int i = 0;  i < 11; i++)
		printf("%c", des[i]);
	printf("\n");
	ft_strncpy(des, src, 2);
	for(int i = 0;  i < 11; i++)
		printf("%c", des[i]);
	printf("\n");
	ft_strncpy(des, src, 7);
	for(int i = 0;  i < 11; i++)
		printf("%c", des[i]);
	/*for(int i = 0;  i < 5; i++)
		printf('\0');*/
	//for(int i = 0;  i < 5; i++)
		//printf("c");
}
