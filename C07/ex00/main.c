/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:38:49 by hoh               #+#    #+#             */
/*   Updated: 2021/10/24 13:40:29 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern char	*ft_strdup(char *str);

int	main(void)
{
	char str[13] = "Hello World!";
	char *cp;

	cp = ft_strdup(str);
	printf("%s", cp);
	free(cp);
}
