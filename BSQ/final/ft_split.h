/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoan <jeoan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:27:38 by jeoan             #+#    #+#             */
/*   Updated: 2021/10/23 23:15:53 by jeoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# include <stdlib.h>

int		ft_is_sep(char ch, char *charset);
int		ft_count_word(char *str, char *charset);
int		ft_count_letter(char **str, char *charset);
void	ft_strncpy_nullt(char *dest, char *src, unsigned int n);
char	**ft_split(char *str, char *charset);

#endif
