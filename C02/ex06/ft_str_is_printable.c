/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:55:19 by hoh               #+#    #+#             */
/*   Updated: 2021/10/18 15:35:46 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	while (str[i] != '\0')
	{	
		if (32 > str[i] | str[i] == 127)
			ret = 0;
		i ++;
	}
	return (ret);
}

int	main(void)
{
	char str1[5] = "a26f";
	char str2[5] = "G'\032~";
	char str3[5] = "2#\n2*";
	char str4[1] = "";

	printf("%d\n", ft_str_is_printable(str1));
	printf("%d\n", ft_str_is_printable(str2));
	printf("%d\n", ft_str_is_printable(str3));
	printf("%d\n", ft_str_is_printable(str4));
}
