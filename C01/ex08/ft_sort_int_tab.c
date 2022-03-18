/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:39:41 by hoh               #+#    #+#             */
/*   Updated: 2021/10/17 15:10:13 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	psort(int *tab, int le, int re)
{
	int	pivot;
	int	left;
	int	right;

	if (le >= re)
		return ;
	pivot = tab[le];
	left = le + 1;
	right = re;
	while (left <= right)
	{
		while (left <= right && tab[right] >= pivot)
			right --;
		while (left <= right && tab[left] <= pivot)
			left ++;
		if (left <= right)
			swap(&tab[left], &tab[right]);
	}
	swap(&tab[le], &tab[right]);
	psort(tab, le, right - 1);
	psort(tab, right + 1, re);
}

void	ft_sort_int_tab(int *tab, int size)
{
	psort(tab, 0, size - 1);
}
