/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:39:12 by ohw               #+#    #+#             */
/*   Updated: 2021/10/26 00:52:03 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_inf
{
	int		row_size;
	char	ec;
	char	oc;
	char	fc;

}t_inf;

int	ft_file_open(const char *path)
{
	return (open(path, O_RDONLY));
}

int	ft_file_read(int file, char *buf, int bfsize)
{
	return (read(file, buf, bfsize));
}

int	n_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i ++;
	return (i);
}

int	get_array_size(char *av)
{
	const int	fd = ft_file_open(av);
	int			rd;
	char		temp[1];
	int			len;

	len = 0;
	if (fd < 0)
		return (0);
	while (1)
	{
		rd = read(fd, temp, 1);
		if (rd < 0)
		{
			close(fd);
			return (0);
		}
		len ++;
		if (!rd)
			break ;
	}
	close(fd);
	return (len + 1);
}

char	*get_array(char *av, int size)
{
	const int		fd = ft_file_open(av);
	char			*ret;

	if (fd < 0)
		return (0);
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (0);
	if (read(fd, ret, size - 1) < 0)
		return (0);
	ret[size - 1] = '\0';
	close(fd);
	return (ret);
}

char	**get_sep_array(char *arr, int size, int i, int j)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 2);
	if (!ret)
		return (0);
	ret[0] = (char *)malloc(sizeof(char) * (n_strlen(arr) + 1));
	ret[1] = (char *)malloc(sizeof(char) * (size - n_strlen(arr) - 1));
	if (!ret[0] | !ret[1] | !(size - n_strlen(arr) - 1))
		return (0);
	while (i <= n_strlen(arr))
	{
		ret[0][j] = arr[i];
		i ++;
		j ++;
	}
	j = 0;
	while (i < size)
	{
		ret[1][j] = arr[i];
		i ++;
		j ++;
	}
	free(arr);
	return (ret);
}

int	ft_atoi(char *str, int len)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < len - 3)
	{
		if (48 > *str | *str > 57)
			return (0);
		ret *= 10;
		ret = ret + *str - 48;
		str ++;
		i ++;
	}
	return (ret);
}

int	inf_error(char *inf)
{
	int	i;
	int	j;
	int	len;

	len = n_strlen(inf);
	if (len < 4)
		return (0);
	i = 1;
	while (i < 4)
	{
		if (inf[len - i] < 32 | inf[len - i] >= 127)
			return (0);
		j = len;
		while (j > len - i)
		{
			if (inf[len - i] == inf[j])
				return (0);
			j --;
		}
		i ++;
	}
	return (ft_atoi(inf, len));
}

int	word_error(char *str, char *inf, int inflen)
{
	int	i;
	int	flag;

	while (*str != '\n')
	{
		i = 1;
		flag = 0;
		while (i < 3)
		{
			if (*str == inf[inflen - 1 - i])
				flag = 1;
			i ++;
		}
		if (!flag)
			return (1);
		str ++;
	}
	return (0);
}

int	line_error(char *temp, int i, int len, char *str0)
{
	int	old_len;

	old_len = len;
	while (*temp)
	{
		len = n_strlen(temp);
		if (len != old_len)
			return (0);
		old_len = len;
		if (word_error(temp, str0, n_strlen(str0)))
			return (0);
		temp += len + 1;
		i ++;
	}
	return (i);
}

int	error_check(char **str, int i)
{
	t_inf		inf;
	const int	infarr = inf_error(str[0]);
	int			len;
	int			old_len;
	char		*temp;

	len = n_strlen(str[1]);
	old_len = len;
	if (!infarr)
		return (0);
	inf.row_size = infarr;
	inf.fc = str[0][n_strlen(str[0]) - 1];
	inf.oc = str[0][n_strlen(str[0]) - 2];
	inf.ec = str[0][n_strlen(str[0]) - 3];
	temp = str[1];
	i = line_error(temp, i, len, str[0]);
	if (i != inf.row_size | i == 0)
		return (0);
	return (1);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	char	**map2;
	int		size;
	char	*map1;
	int		error;

	if (ac > 2)
		return (1);
	size = get_array_size(av[1]);
	map1 = get_array(av[1], size);
	if (!map1)
	{
		printf("에러\n");
		return (-1);
	}
	map2 = get_sep_array(map1, size, 0, 0);
	if (!map2)
	{
		printf("에러\n");
		return (-1);
	}
	error = error_check(map2, 0);
	if (!error)
		printf("에러\n");
	printf("%s", map2[1]);
	//free(map);
}
