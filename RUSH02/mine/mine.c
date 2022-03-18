/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:27:34 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 13:37:05 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

unsigned int ft_atoi(char *str)
{
    unsigned int i;
    unsigned int num;

    i = 0;
    num = 0;
    while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num *= 10;
        num += str[i++] - '0';
    }
    return (num);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(int from, int to, char *str)
{
    int i;
    char *copy;
    int size;

    i = 0;
    size = to - from;
    copy = (char *)malloc(sizeof(char) * size + 1);
    while (i < size)
    {
        copy[i] = str[from + i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

int	total(int size, char **strs, char *sep)
{
	int	i;
	int	sizes;

	i = 0;
	sizes = 0;
	if (size < 1)
		return (0);
	else if (size == 1)
		return (ft_strlen(strs[0]));
	while (i < size)
	{
		sizes += ft_strlen(strs[i]);
		i++;
	}
	return (sizes + ft_strlen(sep) * (i - 1));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = malloc(sizeof(char) * total(size, strs, sep));
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			str[k++] = sep[j++];
		i++;
	}
	str[k] = '\0';
	return (str);
}

int count_sep(char *str, char sep)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == sep)
            c++;
        i++;
    }
    return (c);
}

char **ft_split(char *str, char sep)
{
    int i;
    int j;
    char **num_and_str;
    int size;
    int k;

    k = 0;
    size = count_sep(str, sep) + 1;
    num_and_str = (char **)malloc(sizeof(char *) * (size + 1));
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == sep)
        {
            if (i != j)
                num_and_str[k++] = ft_strdup(j, i, str);
            j = i + 1;
        }
        i++;
    }
	if (j != i)
    	num_and_str[k++] = ft_strdup(j, i, str);
    num_and_str[k] = 0;
    return (num_and_str);
}

char	*ft_strip(char *str)
{
	char	**splitted;
	char	*stripped;
	int		size;

	size = 0;
	splitted = ft_split(str, ' ');
	while (splitted[size])
		size++;
	stripped = ft_strjoin(size, splitted, " ");
	return (stripped);
}

int check_dict_num(int to, char *str)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while (((str[i] >= 8 && str[i] <= 13) || str[i] == 32) && i < to)
        i++;
    if (str[i] == '-' && i < to)
        return (0);
    else if (str[i] == '+' && i < to)
        i++;
    while (str[i] >= '0' && str[i] <= '9' && i < to)
    {
        c++;
        i++;
    }
    if (c == 0)
        return (0);
    return (1);
}

int check_arg_num(char *str)
{
    int   i;
    long  num;

    i = 0;
    num = 0;
    if (str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        num = num * 10 + (str[i] - '0');
        if (num > 4294967295)
            return (0);
        i++;
    }
    return (1);
}
// 예외처리 고민 필요
int check_valid(char *str)
{
    int i;
    int j;
    int c;

    i = 0;
    c = 0;
    // colon 개수 세기
    while (str[i])
    {
        if (str[i] == ':')
        {
            j = i;
            c++;
        }
        i++;
    }
    if (c != 1)
        return (0);
    // 숫자 유효성 체크
    if (!check_dict_num(j, str))
        return (0);
    // 문자 유효성 체크
    j += 1;
    while(str[j])
    {
        if (str[j] <= 31 || str[j] >= 127)
            return (0);
        j++;
    }
    return (1);
}

char  *get_value(unsigned int key, char **dict, int flag)
{
    int   i;
    char  **key_value;

    i = 0;
    while (dict[i])
    {
        key_value = ft_split(dict[i], ':');
        if (ft_atoi(key_value[0]) == key)
        {
            if (key != 0)
                return (ft_strip(key_value[1]));
            else if(key == 0 && flag == 1)
                return (ft_strip(key_value[1]));
            else if (key == 0 && flag == 0)
                return (0);
        }
        i++;
    }
    return (0);
}

void    putstr(int k, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i ++;
    }
	if (k != 0)
		write(1, " ", 1);
}

void print_digit(int i, char *str, char **dict)
{
    if (!str)
        return ;
    putstr(i, str);
    if (i % 3 == 2)
        putstr(i, get_value(100, dict, 0));
    if (i == 3)
        putstr(i, get_value(1000, dict, 0));
    else if (i == 6)
        putstr(i, get_value(1000000, dict, 0));
    else if (i == 9)
        putstr(i, get_value(1000000000, dict, 0));
}

int	print(int i, int num, char **dict)
{
    if (num == 0)
    {
        if  (i == 0)
            putstr(i, get_value(0, dict, 1));
        return (0);
    }
	if (print(i + 1, num / 10, dict))
	{
	    print_digit(i, get_value(num % 10 + 10, dict, 0), dict);
	    return (0);
	}
	else
	{
	    if (i % 3 == 2)
	        print_digit(i, get_value(num % 10, dict, 0), dict);
	    else if (i % 3 == 1)
	    {
	        if (num % 10 == 1)
	            return (1);
	        else
	            print_digit(i,get_value((num % 10) * 10, dict, 0), dict);
	    }
	    else
	        print_digit(i, get_value(num % 10, dict, 0), dict);
	    return (0);
	}
}

char *get_buf(char *file)
{
    int fd;
    int size;
    char temp[1];
    char *buf;
    int r;

    size = 0;
    temp[0] = '1';
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    while (1)
    {
        r = read(fd, temp, 1);
        if (r < 0)
        {
            close(fd);
            return (0);
        }
        else if (r == 0)
            break;
        size ++;
    }
    close(fd);
    fd = open(file, O_RDONLY);
    buf = (char *)malloc(size);
    if (fd < 0 | buf == 0 | read(fd, buf, size) < 0)
        return (0);
    close(fd);
    return (buf);
}

int main(int ac, char **av) {
    char *ret;
    char **dict;
    int i;
    int size;


	dict = 0;
    if (ac > 3 | ac < 2)
        return (-1);
    else if (ac == 3)
    {
        ret = get_buf(av[1]);
        //유효성 점검 추가
        print(0, ft_atoi(av[2]), dict);
    }
    else
    {
        ret = get_buf("/Users/hoh/42git/ohw42/RUSH02/mine/numbers.dict");
        //유효성 점검 추가
        // 인자검사
        if (!check_arg_num(av[1]))
        {
            write(2, "Error\n", 6);
            return (0);
        }
        // 딕셔너리검사
        dict = ft_split(ret, '\n');
        i = 0;
        size = count_sep(ret, '\n');
        while (i < size)
        {
            if (!check_valid(dict[i]))
            {
                write(2, "Dict Error\n", 11);
                return (0);
            }
            i++;
        }
        print(0, ft_atoi(av[1]), dict);
    }
    if (ret == 0)
        return (-1);

    free(ret);
    return 0;
}
