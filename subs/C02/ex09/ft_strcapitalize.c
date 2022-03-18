/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:28:00 by hoh               #+#    #+#             */
/*   Updated: 2021/10/21 10:06:56 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalpnum(char c)
{
	int	ret;

	ret = 0;
	if (47 < c && c < 58)
		ret = 1;
	if (64 < c && c < 91)
		ret = 2;
	if (96 < c && c < 123)
		ret = 3;
	return (ret);
}

char	*ft_strcapitalize(char *str)
{
	char	*origin;

	origin = str;
	while (*str != '\0')
	{
		if (isalpnum(*str))
		{
			if (isalpnum(*str) == 3)
				*str -= 32;
			str ++;
			while (isalpnum(*str))
			{
				if (isalpnum(*str) == 2)
					*str += 32;
				str ++;
			}
		}
		else
			str ++;
	}
	return (origin);
}
