/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:07:22 by hoh               #+#    #+#             */
/*   Updated: 2021/10/21 20:26:32 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*rethex(char c, char ret[])
{
	const char	hex[17] = "0123456789abcdef";
	int			i;

	i = 1;
	while (c != 0)
	{
		ret[i] = hex[c % 16];
		c /= 16;
		i --;
	}
	if (ret[0] != '1' | ret[0] != '7')
		ret[0] = '0';
	return (ret);
}

void	ft_putstr_non_printable(char *str)
{
	char	ret[2];

	while (*str != '\0')
	{
		if (0 <= *str && *str < 32 | *str == 127) //확장 아스키 코드를 위해 얘를 127보다 크게 하고 
												  //unsigned char 로 선언해서 256까지 받을 수 있게!
		{
			write(1, "\\", 1);
			write(1, (rethex(*str, ret)), 2);
		}
		else
			write(1, &(*str), 1);
		str ++;
	}
}

int	main(void)
{
	char str[100] = "Coucou\ntu vas bien ?";
	char str1[100] = "Coucou\ttu vas bien ?";
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	ft_putstr_non_printable(str1);
}
