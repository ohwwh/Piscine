/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:55:08 by ohw               #+#    #+#             */
/*   Updated: 2021/10/21 19:13:44 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	ret;
	int	i;

	ret = 1;
	i = 1;
	if (power < 0)
		return (0);
	while (i <= power)
	{
		ret *= nb;
		i ++;
	}
	return (ret);
}

int	main(void)
{
	printf("%d", ft_iterative_power(0, 0));
	printf("%d", ft_iterative_power(0, 5));
	printf("%d", ft_iterative_power(-2, 3));
	printf("%d", ft_iterative_power(2, 0));
}
