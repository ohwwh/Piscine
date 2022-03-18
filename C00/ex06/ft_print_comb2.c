/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:54:15 by hoh               #+#    #+#             */
/*   Updated: 2021/10/17 10:31:17 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	back(char fr[])
{
	char	br[2];
	char	a;
	char	b;

	a = fr[0];
	while (a <= '9')
	{
		br[0] = a;
		if (a == fr[0])
			b = fr[1] + 1;
		else
			b = '0';
		while (b <= '9')
		{	
			br[1] = b;
			write(1, fr, 2);
			write(1, " ", 1);
			write(1, br, 2);
			if (fr[0] != '9' | fr[1] != '8')
				write(1, ", ", 2);
			b += 1;
		}	
		a += 1;
	}
}

void	front(void)
{
	char	fr[2];
	char	a;
	char	b;

	a = '0';
	b = '0';
	while (a <= '9')
	{
		fr[0] = a;
		while (b <= '9')
		{
			fr[1] = b;
			back(fr);
			b += 1;
		}
		a += 1;
		b = '0';
	}
}

void	ft_print_comb2(void)
{
	front();
}
