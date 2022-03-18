/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:11:32 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 10:09:50 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	int	x;

	if (nb == 1 | nb <= 0)
		return (0);
	x = 2;
	while (x * x <= nb)
	{
		if (nb % x == 0)
			return (0);
		x ++;
		if (x > 46340)
			return (1);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (is_prime(i) == 0)
		i ++;
	return (i);
}
