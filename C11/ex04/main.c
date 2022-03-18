/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:27:42 by ohw               #+#    #+#             */
/*   Updated: 2021/10/29 00:01:46 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern	int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int	isbigger(int x, int y)
{
	if (x > y)
		return (1);
	else if (x == y)
		return (0);
	else
		return (-1);
}

int	main(void)
{
	int	str[8] = {1, 2, 1, 4, 5, 6, 7, 8};
	printf("%d", ft_is_sort(str, 8, &isbigger));
}
