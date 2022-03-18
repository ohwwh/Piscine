/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:48:54 by hoh               #+#    #+#             */
/*   Updated: 2021/10/25 11:08:41 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	error(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac < 2)
			write(1, "File name missing.", 18);
		if (ac > 2)
			write(1, "Too many arguments.", 19);
		return (-2);
	}
	return (open(av[1], O_RDONLY));
}

int	main(int ac, char **av)
{
	int		fd;
	char	tmp[1];
	int		rd;

	tmp[0] = 'c';
	fd = error(ac, av);
	if (fd < 0)
	{
		if (fd == -1)
			write(1, "Cannot read file.", 17);
		return (-1);
	}
	while (1)
	{
		rd = read(fd, tmp, 1);
		if (rd == 0)
			break ;
		else if (rd < 0)
		{
			write(1, "Cannot read file.", 17);
			return (-1);
		}
		write(1, tmp, 1);
	}
	close(fd);
}
