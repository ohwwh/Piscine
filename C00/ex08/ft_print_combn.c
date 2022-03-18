/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:54:15 by hoh               #+#    #+#             */
/*   Updated: 2021/10/17 10:31:37 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(int i, int n, char c, char a[])
{
	if (i <= n)
	{
		while (c <= '9')
		{
			a[i - 1] = c;
			recur(i + 1, n, c + 1, a);
			c += 1;
		}
	}	
	else
	{
		if (a[n - 1] != n - 1 + '0')
			write(1, ", ", 2);
		write(1, a, n);
	}
}

void	ft_print_combn(int n)
{
	char	ar[10];
	char	a;

	a = '0';
	recur(1, n, a, ar);
}
