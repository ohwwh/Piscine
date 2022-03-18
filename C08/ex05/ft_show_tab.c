/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:50:31 by ohw               #+#    #+#             */
/*   Updated: 2021/10/26 17:07:17 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

extern	struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	printint(int n)
{
	char c;

	c = n % 10 + '0';
	if (n == 0)
		return ;
	printint(n / 10);
	write(1, &c, 1);
}

void	printstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str ++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{	
		printstr(par[i].str);
		write(1, "\n", 1);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			printint(par[i].size);
		write(1, "\n", 1);
		printstr(par[i].copy);
		write(1, "\n", 1);
		i ++;
	}
}
