/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:13:15 by hoh               #+#    #+#             */
/*   Updated: 2021/10/26 11:22:19 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern	char	**ft_split(char *str, char *sep);

int main(void)
{
    char str[100] = "   Myu  life d  for  Aierrrrr  ";
    char **ret;
	int	i;

	i = 0;
    ret = ft_split(str, "d  ");
    while (ret[i])
	{
		printf("%s\n", ret[i]);
		free(ret[i]);
		i ++;
	}
}
