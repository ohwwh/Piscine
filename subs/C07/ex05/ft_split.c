/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:46:55 by ohw               #+#    #+#             */
/*   Updated: 2021/10/26 11:41:45 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_word(char c, char *charset)
{
	int	i;

	i = 0;
	if (c == 0)
		return (0);
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (0);
		i ++;
	}
	return (1);
}

int	len_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (is_word(str[i], charset))
		i ++;
	return (i);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (is_word(str[i], charset))
		{
			count ++;
			while (is_word(str[i], charset) && str[i])
				i ++;
		}
		else
			i ++;
	}
	return (count);
}

char	**ft_split2(char *str, char *charset, int i, int j)
{
	char	**ret;
	int		k;
	int		len;

	ret = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	while (str[i] != 0)
	{
		if (is_word(str[i], charset))
		{
			k = 0;
			len = len_word(&str[i], charset);
			ret[j] = (char *)malloc(sizeof(char) * (len + 1));
			while (is_word(str[i], charset) && str[i])
			{
				ret[j][k] = str[i];
				k ++;
				i ++;
			}
			ret[j][k] = '\0';
			j ++;
		}
		else
			i ++;
	}
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;

	ret = ft_split2(str, charset, 0, 0);
	ret[count_word(str, charset)] = 0;
	return (ret);
}
