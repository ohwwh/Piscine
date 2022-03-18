/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:24:57 by ohw               #+#    #+#             */
/*   Updated: 2021/10/28 23:44:44 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	if (length == 1)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i + 1], tab[i]) < 0)
		{
			while (i < length - 1)
			{
				if (f(tab[i + 1], tab[i]) > 0)
					return (0);
				i ++;
			}
		}
		else if (f(tab[i + 1], tab[i]) > 0)
		{
			while (i < length - 1)
			{
				if (f(tab[i + 1], tab[i]) < 0)
					return (0);
				i ++;
			}
		}
		else
			i ++;
	}
	return (1);
}
