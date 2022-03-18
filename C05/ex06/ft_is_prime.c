/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:44:28 by ohw               #+#    #+#             */
/*   Updated: 2021/10/15 01:02:56 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	arr[nb + 1];
	int i;
	int j;

	i = 2;
	j = 2;
	arr[2] = 0;
	while (i <= nb)
	{
		if (arr[i] == 0)
		{
			while (i * j <=nb)
			{
				arr[i * j] = 1;
				j ++;
			}
		}
		i ++;
		j = 2;
	}
	if (arr[nb] == 0)
		return (1);
	else
		return (0);
}

int	main(void)
{
	printf("%d\n", ft_is_prime(7));
	printf("%d\n", ft_is_prime(15));
}
