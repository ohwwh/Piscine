/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:12:23 by hoh               #+#    #+#             */
/*   Updated: 2021/10/21 18:58:49 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexcharrecur(char c, char o, const char *base)
{
	if (c == 0)
	{
		if (0 < o && o <= 15)
			write(1, "0", 1);
		else if (o == 0)
			write(1, "00", 2);
		return ;
	}
	hexcharrecur(c / 16, o, base);
	write(1, &base[c % 16], 1);
}

void	hexchar(char *addr, unsigned int len)
{
	char		temp;
	const char	base[17] = "0123456789abcdef";

	temp = *addr;
	hexcharrecur(temp, temp, base);
	if (len % 2 == 1)
		write(1, " ", 1);
}

void	hexaddr(long addr)
{
	const char	base[17] = "0123456789abcdef";

	if (addr == 0)
	{
		write(1, "0000000", 7);
		return ;
	}
	hexaddr(addr / 16);
	write(1, &base[addr % 16], 1);
}

void	last(char *origin, unsigned int len, unsigned int size)
{
	unsigned int	temp;

	if ((len - 1) % 16 != 15)
	{
		temp = len;
		while (temp < ((size / 16) + 1) * 16)
		{
			write(1, "  ", 2);
			if (temp % 2 == 1)
				write(1, " ", 1);
			temp ++;
		}
		write(1, origin, len % 16);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	len;
	char			*temp;
	char			*origin;

	temp = (char *)addr;
	origin = (char *)addr;
	len = 0;
	while (len < size)
	{	
		if (len % 16 == 0)
		{
			hexaddr((long)(temp + len));
			write(1, ": ", 2);
			origin = temp + len;
		}
		hexchar(temp + len, len);
		if (0 <= *temp && *temp < 32 | *temp >= 127 )
		*(temp + len)  = '.';
		if (len % 16 == 15)
		{
			write(1, origin, 16);
			write(1, "\n", 1);
		}
		len ++;
	}
	last(origin, len, size);
	return (addr);
}
