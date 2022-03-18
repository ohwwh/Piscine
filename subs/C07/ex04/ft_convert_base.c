/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:40:37 by ohw               #+#    #+#             */
/*   Updated: 2021/10/26 11:14:14 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern long	ft_atoi_base(char *str, char *base);
extern int	checkbase(char *base);

int	checkdigit(long nbr, int bs, int digit)
{
	if (nbr == 0)
		return (digit);
	return (checkdigit(nbr / bs, bs, digit + 1));
}

void	allocbase(long nbr, char *base, char *ret, int i)
{
	if (i < 0)
		return ;
	allocbase(nbr / checkbase(base), base, ret, i - 1);
	if (nbr != 0)
	{
		if (nbr < 0)
			ret[i] = base[-(nbr % checkbase(base))];
		else
			ret[i] = base[nbr % checkbase(base)];
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr2;
	char	*ret;
	int		digit;

	if (!checkbase(base_to) | !checkbase(base_from))
		return (0);
	nbr2 = ft_atoi_base(nbr, base_from);
	if (nbr2 < 0)
		digit = checkdigit(-nbr2, checkbase(base_to), 0) + 1;
	else
		digit = checkdigit(nbr2, checkbase(base_to), 0);
	if (!digit)
		digit ++;
	ret = (char *)malloc(digit);
	ret[0] = '0';
	if (ret != 0)
	{
		if (nbr2 == 0)
			return (ret);
		if (nbr2 < 0)
			ret[0] = '-';
		allocbase(nbr2, base_to, ret, digit - 1);
		return (ret);
	}
	return (0);
}
