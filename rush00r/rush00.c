/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:22 by hoh               #+#    #+#             */
/*   Updated: 2021/10/10 15:47:06 by hoh              ###   ########.fr       */
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
			if ((a - 1) * (x - a) == 0 && (b - 1) * (b - y) == 0)
				ft_putchar("o");
			else if ((a - 1) * (x - a) != 0 && (b - 1) * (b - y) != 0)
				ft_putchar(" ");
			else if (b == 1 | b == y)
				ft_putchar("-");
			else
				ft_putchar("|");
			a += 1;
		}
		ft_putchar("\n");
		b += 1;
	}
}
