/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:29:03 by ohw               #+#    #+#             */
/*   Updated: 2021/10/21 21:09:19 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ispossible(char r, char c, char ret[])
{
	char	i;

	i = '0';
	while (i <= c - 1)
	{
		if (r == ret[i - 48])
			return (0);
		if (r - c == ret[i - 48] - i | r + c == ret[i - 48] + i)
			return (0);
		i ++;
	}
	return (1);
}

int	recur(char c, char ret[], int ans)
{
	char	r;

	r = '0';
	if (c > '9')
	{
		write(1, ret, 10);
		write(1, "\n", 1);
		ans ++;
		return (ans);
	}
	while (r <= '9')
	{
		if ((c == '0') | ispossible(r, c, ret))
		{
			ret[c - 48] = r;
			ans = recur(c + 1, ret, ans);
		}
		r ++;
	}
	return (ans);
}

int	ft_ten_queens_puzzle(void)
{
	char	ret[10];

	return (recur('0', ret, 0));
}
