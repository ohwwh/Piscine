/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:21:21 by hoh               #+#    #+#             */
/*   Updated: 2021/10/26 17:07:30 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

extern	struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);
extern	void	ft_show_tab(struct s_stock_str *par);

int	main(int ac, char **av)
{
	t_stock_str *ret;
	
	ret = ft_strs_to_tab(ac, av);
	ft_show_tab(ret);
}
