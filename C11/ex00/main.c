/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:53:40 by hoh               #+#    #+#             */
/*   Updated: 2021/10/28 17:00:56 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

extern	void	ft_foreach(int *tab, int length, void(*f)(int));

void	ft_putnbr(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	tab[5] = {1, 2, 3, 4, 5};
	ft_foreach(tab, 5, &ft_putnbr);
}
