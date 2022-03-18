/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:40:57 by hoh               #+#    #+#             */
/*   Updated: 2021/10/24 14:27:06 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern int	*ft_range(int min, int max);

int	main(void)
{
	int *arr;

	arr = ft_range(1, 7);
	if (!arr)
	{
		printf("널");
		return (0);
	}
	for (int i=0; i < 6; i ++)
		printf("%d", arr[i]);
	free(arr);
}
