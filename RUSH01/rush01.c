/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:03:03 by ohw               #+#    #+#             */
/*   Updated: 2021/10/17 00:54:06 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_shutdown;

void	print(int g_map[][4])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = g_map[i][j] + 48;
			write(1, &c, 1);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
}

int	cluefront(int arr[])
{
	int	ret;
	int	max;
	int	i;

	max = arr[0];
	ret = 1;
	i = 1;
	while (i < 4)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			ret ++;
		}
		i ++;
	}
	return (ret);
}

int	clueback(int arr[])
{
	int	ret;
	int	max;
	int	i;

	max = arr[3];
	ret = 1;
	i = 1;
	while (i < 4)
	{
		if (max < arr[3 - i])
		{
			max = arr[3 - i];
			ret ++;
		}
		i ++;
	}
	return (ret);
}

int	checkarray(int ret[], int line, int givenclue[])
{
	if (givenclue[8 + line] == cluefront(ret))
	{
		if (givenclue[12 + line] == clueback(ret))
			return (1);
	}
	return (0);
}

void	input_array(int i, int j, char c, int givenclue[])
{
	givenclue[i + j] = c - '0';
}

/*int init_limit(char *str, int givenclue[])
{
    int     i;
    int     j;
    int     result;
    i = 0;
    j = 0;
    result = 0;
    while (str[i] != '\0')
    {
        input_array(i, j, str[i], givenclue);
        result++;
        j++;
        i++;
    }
    return (result);
}*/

int	vfinish(int g_map[][4], int givenclue[])
{
	int	comp[4];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			comp[j] = g_map[j][i];
			j ++;
		}
		if (!checkarray(comp, i - 8, givenclue))
			return (0);
		i ++;
	}
	return (1);
}

int	hfinish(int g_map[][4], int givenclue[])
{
	int	comp[4];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			comp[j] = g_map[i][j];
			j ++;
		}
		if (!checkarray(comp, i, givenclue))
			return (0);
		i ++;
	}
	return (1);
}

int	check(int x, int y, int next, int g_map[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_map[i][x] == next || g_map[y][i] == next)
			return (0);
		i++;
	}
	return (1);
}

void	dfs(int d, int givenclue[], int g_map[][4])
{
	int	div;
	int	mod;
	int	i;

	div = d / 4;
	mod = d % 4;
	i = 1;
	if (!g_shutdown)
	{
		if (d >= 16)
		{
			if (vfinish(g_map, givenclue) && hfinish(g_map, givenclue))
			{
				print(g_map);
				g_shutdown = 1;
				return;
			}
		}
		while (i <= 4)
		{
			if (check(mod, div, i, g_map))
			{
				g_map[div][mod] = i;
				dfs(d + 1, givenclue, g_map);
				g_map[div][mod] = 0;
			}
			i ++;
		}
	}
}

void	init_map(int g_map[][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			g_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	g_map[4][4];
	int	givenclue[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	/*if (argc != 2)
    {
        write(1, "Error\n", 5);
        return (1);
    }
    if (init_limit(argv[1], givenclue) != 16)
    {
        write(1, "Error\n", 5);
        return (1);
    }*/
	init_map(g_map);
	g_shutdown = 0;
	dfs(0, givenclue, g_map);
	return (0);
}
