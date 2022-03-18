/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:07:22 by hoh               #+#    #+#             */
/*   Updated: 2021/10/21 16:59:55 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rethex(char c, char o, const char *base)
{
	if (c == 0)
	{
		if (1 <= o && o <= 15)
			write(1, "0", 1);
		else if (o == 0)
			write(1, "00", 2);
		return ;
	}
	rethex(c / 16, o, base);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	const char	hex[17] = "0123456789abcdef";

	while (*str != '\0')
	{
		if (0 <= *str && *str < 32 | *str >= 127)
		{
			write(1, "\\", 1);
			rethex(*str, *str, hex);
		}
		else
			write(1, &(*str), 1);
		str ++;
	}
}
