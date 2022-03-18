/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:44:58 by ohw               #+#    #+#             */
/*   Updated: 2021/10/19 10:17:34 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		j;
	char	*find;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		j = 0;
		while (*str == to_find[j])
		{
			if (j == 0)
				find = str;
			str ++;
			j ++;
			if (to_find[j] == '\0')
				return (find);
			if (to_find[j] != '\0' && *str == '\0')
				return (0);
		}
		str ++;
	}
	return (0);
}
