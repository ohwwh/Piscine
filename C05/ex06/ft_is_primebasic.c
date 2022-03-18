/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_primebasic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:03:22 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 10:00:16 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	x;

	if (nb == 1 | nb <= 0)
		return (0);
	x = 2;
	while (x * x <= nb)
	{
		if (nb % x == 0)
			return (0);
		x ++;
		if (x > 46340)
			return (1);
	}
	return (1);
}

int	main(void)
{
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(127));
	printf("%d\n", ft_is_prime(15));
}
