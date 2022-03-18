/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:34:54 by ohw               #+#    #+#             */
/*   Updated: 2021/10/19 10:23:46 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*tmp;

	tmp = dest;
	i = 1;
	while (*dest != '\0')
		dest ++;
	while (i <= nb && *src != '\0')
	{
		*dest = *src;
		i ++;
		dest ++;
		src ++;
	}
	*dest = '\0';
	return (tmp);
}
