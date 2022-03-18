/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:39:37 by ohw               #+#    #+#             */
/*   Updated: 2021/10/25 21:24:04 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_inf
{
	int		row_size;
	char	ec;
	char	oc;
	char	fc;

}t_inf;

int	get_array_size(char *av)
{
	const int	fd = open(av, O_RDONLY);
	int			rd;
	int			temp[1];
	int			len;
	char		*ret;	

	len = 0;
	if (fd < 0)
		return (0);
	while (read(fd, temp, 1))
	{
		if ((rd = read(fd, temp, 1)) < 0)
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
	const int		fd = open(av, O_RDONLY);
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

char	**get_sep_array(char *arr, int size)
{
	int		first_len;
	int		i;
	int		j;
	char	**ret;

	i = 0;
	first_len = 0;
	while (arr[first_len] != '\n')
		first_len ++;
	ret = (char **)malloc(sizeof(char *) * 2);
	if (!ret)
		return (0);
	ret[0] = (char *)malloc(sizeof(char) * (first_len + 1));
	ret[1] = (char *)malloc(sizeof(char) * (size - first_len - 1));
	if (!ret[0] | !ret[1])
		return(0);
	j = 0;
	while (i <= first_len)
	{
		ret[0][j] = arr[i];
		i ++;
		j ++;
	}
	j = 0;
	while (i <= size)
	{
		ret[1][j] = arr[i];
		i ++;
		j ++;
	}
	free(arr);
	return (ret);
}

int	ft_file_open(const char *path)
{
	return (open(path, O_RDONLY));
}

int	ft_file_close(int fd)
{
	return (close(fd));
}

int	line_len(int fd)
{
	char	tmp[1];
	int		i;

	i = 0;
	while (tmp[0] != '\n')
	{
		read(fd, tmp, 1);
		i ++;
	}
	close(fd);
	return (i);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	i;
	int	len;

	len = 0;
	while (str[len] != '\n')
		len ++;
	i = 0;
	ret = 0;
	while (i < len - 4)
	{	
		ret *= 10;
		ret = ret + *str - 48;
		str ++;
		if (48 > *str | *str > 57)
			return (-1);
		i ++;
	}
	return (ret);
}

int	inf_error(char *inf, int fd, int len) //첫 행에 주어진 정보에 오류가 없는지 검사
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;

	while (i < 3)
	{
		if (inf[len - i] < 32 | inf[len - i] >= 127)
			ret = 1;
		j = len;
		while (j > i)
		{
			if (inf[len - i] == inf[j])
				ret = 1;
			j --;
		}
		i --;
	}
	if (ret == 1)
		close(fd);
	return (ret);
}

int	len_error(int i, int old_len, int len, int fd) //모든 행의 길이가 같은지 검사
{
	if (i != 0)
	{
		if (len != old_len)
		{
			close(fd);
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

int	line_error(char *inf, int i, int old_len, int fd) //주어진 라인 수와 실제 라인수가 같은지, 혹은 최소 1개의 라인이 존재하는지 검사
{
	close(fd);
	if (i == 0)
		return (-1);
	if (i == inf[0] - '0')
		return (old_len);
	else
		return (-1);
}

int	right_word(char c, char *inf) //읽은 문자가 첫행에 있는 문자인지 검사
{
	int	i;

	i = 1;
	if (c == '\n')
		return (1);
	while (i < 4)
	{
		if (c == inf[i])
			return (1);
		i ++;
	}
	return (0);
}

int	error_check(const char *av, char *inf, int i, int old_len)
{
	int			fd;
	char		tmp[1];
	int			len;
	int			first_line;

	fd = ft_file_open(av);
	if (fd < 0)
		return (-1);
	first_line = line_len(fd);
	inf = (char *)malloc(sizeof(char) * first_line);
	fd = ft_file_open(av);
	read(fd, inf, first_line);
	if (inf_error(inf, fd, first_line))
		return (-1);
	while (1)
	{
		len = 0;
		while (1)
		{
			if (read(fd, tmp, 1) == 0)
				return (line_error(inf, i, old_len, fd));
			if (!right_word(tmp[0], inf))
				return (-1);
			if (tmp[0] == '\n')
				break ;
			len ++;
		}
		if (len_error(i, len, old_len, fd))
			return (-1);
		old_len = len;
		i ++;
	}
}

char	*create_map(const char *av)
{
	const int		fd = ft_file_open(av);
	char			*inf;
	int				len;
	int				i;
	char			*map;

	i = 0;
	len = error_check(av, inf, 0, 0);
	if (fd < 0 | len < 0 | read(fd, inf, 5) < 0)
	{
		close(fd);
		return (0);
	}
	map = (char *)malloc(sizeof(char ) * (inf[0] - '0') * (len + 1) + 1);
	while (map && i < inf[0] - '0')
	{
		if (read(fd, (map + (len + 1) * i), len + 1) < 0)
			return (0);
		i ++;
	}
	close(fd);
	return (map);
}

#include <stdio.h>

int	main(int ac, const char **av)
{
	char	*map;

	if (ac > 2)
		return (1);
	map = create_map(av[1]);
	printf("%s", map);
	free(map);
}
