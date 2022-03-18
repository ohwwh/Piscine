/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:52:34 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/25 19:17:22 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str && ft_is_number(*str))
	{
		result += *str - '0';
		if (ft_is_number(*(str + 1)))
			result *= 10;
		str++;
	}
	return (result);
}