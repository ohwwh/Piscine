/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:55:19 by hoh               #+#    #+#             */
/*   Updated: 2021/10/18 15:27:02 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (65 > str[i] | 90 < str[i])
			ret = 1;
		i ++;
	}
	if (i == 0)
		ret = 1;
	return (ret);
}

int	main(void)
{
	char str1[5] = "a26f";
	char str2[5] = "G32~";
	char str3[5] = "2#2*";
	char str4[1] = "";

	printf("%d\n", ft_str_is_uppercase(str1));
	printf("%d\n", ft_str_is_uppercase(str2));
	printf("%d\n", ft_str_is_uppercase(str3));
	printf("%d\n", ft_str_is_uppercase(str4));
}
