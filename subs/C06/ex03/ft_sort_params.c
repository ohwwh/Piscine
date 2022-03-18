/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:37:41 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 11:37:21 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ismin(char *s1, char *s2)
{
	while ((*s1 != 0 | *s2 != 0) && (*s2 == *s1))
	{
		s1 ++;
		s2 ++;
	}
	if (*s1 >= *s2)
		return (1);
	else
		return (0);
}

void	sort(int ac, char **av)
{
	int		i;
	int		j;
	int		minidx;
	char	*temp;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		minidx = i;
		while (j < ac)
		{
			if (!ismin(av[j], av[minidx]))
				minidx = j;
			j ++;
		}
		temp = av[i];
		av[i] = av[minidx];
		av[minidx] = temp;
		i ++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	sort(ac, av);
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			write(1, &av[i][j], 1);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
}
