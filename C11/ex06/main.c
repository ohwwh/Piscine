/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:43:04 by ohw               #+#    #+#             */
/*   Updated: 2021/10/29 00:46:05 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern	void	ft_sort_string_tab(char **tab);

int	main(void)
{
	int	i;

	i = 0;
	char	*str[] = {"berry", "banana", "apple", "crow", "demon", "candy"};
	ft_sort_string_tab(str);
	while (str[i])
	{
		printf("%s", str[i]);
	}
}
