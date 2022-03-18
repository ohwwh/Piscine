/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:40:49 by ohw               #+#    #+#             */
/*   Updated: 2021/10/21 09:58:17 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(long n)
{
	char	c;

	if (n == 0)
		return ;
	print(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	n2;

	n2 = (long)n;
	if (n2 == 0)
		write(1, "0", 1);
	else if (n2 < 0)
	{
		write(1, "-", 1);
		print(-n2);
	}
	else
		print(n2);
}
