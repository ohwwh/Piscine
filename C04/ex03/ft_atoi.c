/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:43:43 by ohw               #+#    #+#             */
/*   Updated: 2021/10/19 20:53:39 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while ((9 <= *str && *str <= 13) | (*str == 32))
		str ++;
	while (*str == '+' | *str == '-')
	{	
		if (*str == '-')
			i ++;
		str ++;
	}			
	while (48 <= *str && *str <= 57)
	{	
		ret *= 10;
		ret = ret + *str - 48;
		str ++;
	}
	if (i % 2 == 1)
		return (-ret);
	else
		return (ret);
}

int main(void)
{
	char str[100] = "   --+---+01259ab356";
	printf("%d", ft_atoi(str));
}
