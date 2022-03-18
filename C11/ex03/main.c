/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:18:34 by hoh               #+#    #+#             */
/*   Updated: 2021/10/28 23:20:05 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern	int	ft_count_if(char **tab, int length, int(*f)(char*));

int	isx(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'x')
			return (1);
		i ++;
	}
	return (0);
}

int	main(void)
{
	char *str[] = {"Hello", "he", "XQd", "xORD", "Hax", "aeaX"};
	printf("%d", ft_count_if(str, 6, &isx));
}
