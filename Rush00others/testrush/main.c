/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:07:32 by hoh               #+#    #+#             */
/*   Updated: 2021/10/10 17:56:08 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	rush(int a, int b);

int	main(void)
{
	rush(2, 6);
	printf("\n");
	rush(5, 5);
	printf("\n");
	rush(5, 1);
	printf("\n");
	rush(1, 5);
	printf("\n");
	rush(1, 1);
	printf("\n");
	return (0);
}
