/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:34:13 by hoh               #+#    #+#             */
/*   Updated: 2021/10/28 20:28:15 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern	int	ft_any(char **tab, int(*f)(char *));

int	minus(char *str)
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
	char *str[] = {"Hellx", "hell", "Ho", 0};
	printf("%d", ft_any(str, &minus));
}
