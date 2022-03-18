/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:30:17 by hoh               #+#    #+#             */
/*   Updated: 2021/10/10 18:30:24 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top(int x)
{
	int		i;

	i = 2;
	ft_putchar('A');
	while (i < x && x >= 3)
	{
		ft_putchar('B');
		i++;
	}
	if (x >= 2)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	center(int x, int y)
{
	int		i;
	int		space;

	i = 2;
	while (i < y)
	{
		ft_putchar('B');
		space = 1;
		while (space <= x - 2)
		{
			ft_putchar(' ');
			space++;
		}
		if (x >= 2)
		{
			ft_putchar('B');
		}
		i++;
		ft_putchar('\n');
	}
}

void	bottom(int x)
{
	int		i;

	i = 2;
	ft_putchar('A');
	while (i < x && x >= 3)
	{
		ft_putchar('B');
		i++;
	}
	if (x >= 2)
	{
		ft_putchar('C');
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
			bottom(x);
		}
	}
}
