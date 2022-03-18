/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:22 by hoh               #+#    #+#             */
/*   Updated: 2021/10/10 15:48:05 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char *c);

void	rush(int x, int y)
{
	int	a;
	int	b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			if (b == 1 && (a == 1 | a == x))
				ft_putchar("A");
			else if (b == y && (a == 1 | a == x))
				ft_putchar("C");
			else if ((a - 1) * (x - a) != 0 && (b - 1) * (b - y) != 0)
				ft_putchar(" ");
			else
				ft_putchar("B");
			a += 1;
		}
		ft_putchar("\n");
		b += 1;
	}
}
