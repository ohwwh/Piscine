/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:30:59 by ohw               #+#    #+#             */
/*   Updated: 2021/10/29 01:21:05 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count(char **tab)
{
	int	count;
	
	count = sizeof(tab) / sizeof(tab[0]);
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 | *s2))
	{
		s1 ++;
		s2 ++;
	}
	if (*s1 >= *s2)
		return (1);
	else
		return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		minidx;
	char	*temp;

	i = 0;
	while (i < count(tab))
	{
		j = i + 1;
		minidx = i;
		while (i < count(tab))
		{
			if (!ft_strcmp(tab[j], tab[minidx]))
				minidx = j;
			j ++;
		}
		temp = tab[i];
		tab[i] = tab[minidx];
		tab[minidx] = temp;
		i ++;
	}
}
