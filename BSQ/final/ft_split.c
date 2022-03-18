/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:27:38 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/24 03:56:06 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	ft_is_sep(char ch, char *charset)
{
	while (*charset)
	{
		if (ch == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int		is_prev_sep;
	int		count;

	count = 0;
	is_prev_sep = 1;
	while (*str)
	{
		if (!ft_is_sep(*str, charset) && is_prev_sep)
			count++;
		if (ft_is_sep(*str, charset))
			is_prev_sep = 1;
		else
			is_prev_sep = 0;
		str++;
	}
	return (count);
}

int	ft_count_letter(char **str, char *charset)
{
	int	count;

	count = 0;
	while (**str && ft_is_sep(**str, charset))
		(*str)++;
	while (**str && !ft_is_sep(**str, charset))
	{
		(*str)++;
		count++;
	}
	return (count);
}

void	ft_strncpy_nullt(char *dest, char *src, unsigned int n)
{
	while (n-- && *src)
		*dest++ = *src++;
	*dest++ = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		word;
	int		letter;
	char	**array;

	word = ft_count_word(str, charset);
	array = (char **)malloc((word + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	index = 0;
	while (index < word)
	{
		letter = ft_count_letter(&str, charset);
		array[index] = (char *)malloc((letter + 1) * sizeof(char));
		if (!array[index])
			return (NULL);
		str -= letter;
		ft_strncpy_nullt(array[index], str, letter);
		str += letter;
		index++;
	}
	array[index] = NULL;
	return (array);
}
