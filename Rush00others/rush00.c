/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:29:54 by hoh               #+#    #+#             */
/*   Updated: 2021/10/10 18:29:56 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top(int x)
{
	int	i;

	i = 2;
	ft_putchar('o');
	while (i < x && x >= 3)
	{
		ft_putchar('-');
		i++;
	}
	if (x >= 2)
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	center(int x, int y)
{
	int	i;
	int	space;

	i = 2;
	while (i < y)
	{
		ft_putchar('|');
		space = 1;
		while (space <= x - 2)
		{
			ft_putchar(' ');
			space++;
		}
		if (x >= 2)
		{
			ft_putchar('|');
		}
		i++;
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x >= 1 && y >= 1)
	{
		top(x);
		if (y >= 3)
		{
			center(x, y);
		}
		if (y >= 2)
		{
			top(x);
		}
	}
	ft_putchar('\n');
}
