/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:37:53 by ohw               #+#    #+#             */
/*   Updated: 2021/10/21 11:42:54 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{	
	while (*str != '\0')
		write(1, str ++, 1);
}

int	main(void)
{
	char str[10] = "HelloWorld";
	ft_putchar(str);
}
