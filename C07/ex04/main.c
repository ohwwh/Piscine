/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:37:47 by hoh               #+#    #+#             */
/*   Updated: 2021/10/26 11:16:12 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern char *ft_convert_base(char *str, char *basef, char *baset);

int main(void)
{
    char str[100] = "  -+- 00300geg6";
    char basef[17] = "0123456789abcdef";
    char baset[9] = "01234567";
    char *ret;

    ret = ft_convert_base(str, basef, baset);
	if (ret == 0)
	{
		printf("널");
		return (0);
	}
    printf("%s", ret);
	free(ret);
}
