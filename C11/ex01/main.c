/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:11:17 by hoh               #+#    #+#             */
/*   Updated: 2021/10/28 17:15:07 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern	int	*ft_map(int *tab, int length, int(*f)(int));

int	plus(int a)
{
	a ++;
	return (a);
}

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4 ,5};
	int	*ret;

	ret = ft_map(tab, 5, &plus);
	for (int i=0; i<5; i ++)
		printf("%d", ret[i]);
	if (ret)
		free(ret);
}
