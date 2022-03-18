/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:13:31 by ohw               #+#    #+#             */
/*   Updated: 2021/10/26 10:59:01 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' | base[i] == '+' | base[i] == ' ')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j ++;
		}
		i ++;
	}
	if (i == 1)
		i = 0;
	return (i);
}

int	isbase(char c, char *base)
{
	int	ret;
	int	i;

	i = 0;
	ret = -1;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i ++;
	}
	return (ret);
}

int	power(int n, int x)
{
	if (x == 0)
		return (1);
	return (n * power(n, x - 1));
}

int	neg(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == '-')
			i ++;
		str ++;
	}
	if (i % 2 == 1)
		return (-1);
	else
		return (1);
}

long	ft_atoi_base(char *str, char *base)
{
	int			i;
	long		ret;
	char		*start;
	const int	n = neg(str);

	if (checkbase(base) == 0)
		return (0);
	i = 0;
	ret = 0;
	while ((9 <= *str && *str <= 13) | (*str == ' '))
		str ++;
	while (*str == '+' | *str == '-')
		str ++;
	start = str;
	while (isbase(*str, base) != -1)
		str ++;
	if (start == str)
		return (0);
	while (str != start)
	{
		str --;
		ret = ret + isbase(*str, base) * power(checkbase(base), i);
		i ++;
	}
	return (n * ret);
}
