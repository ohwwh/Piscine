/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:11:30 by hoh               #+#    #+#             */
/*   Updated: 2021/10/21 18:43:42 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' | base[i] == '+')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j ++;
		}
		i ++;
	}
	if (i == 1)
		i = 0;
	return (i);
}

void	printbase(long nbr, char *base, int bs)
{
	if (nbr == 0)
		return ;
	printbase(nbr / bs, base, bs);
	write(1, &base[nbr % bs], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		bs;
	long	nbr2;

	nbr2 = (long)nbr;
	bs = checkbase(base);
	if (checkbase(base) != 0)
	{
		if (nbr == 0)
			write(1, "0", 1);
		else if (nbr < 0)
		{
			write(1, "-", 1);
			printbase(-nbr2, base, bs);
		}
		else
			printbase(nbr2, base, bs);
	}
}

int	main(void)
{
	char base[17] = "0123456789abcdef";
	ft_putnbr_base(-21474, base);
}
