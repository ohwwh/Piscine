/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:36:09 by ohw               #+#    #+#             */
/*   Updated: 2021/10/21 10:32:40 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	temp;

	temp = 1;
	while (temp * temp <= nb)
	{
		if (temp * temp == nb)
			return (temp);
		temp ++;
		if (temp > 46340)
			return (0);
	}
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(2147483647));
}
