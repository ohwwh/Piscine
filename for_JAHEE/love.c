#include <stdio.h>
#include <math.h>
#include <string.h>

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

void	printheart(char *message)
{
	int size = 10;
 
	int n = strlen(message);
 
	int print_line = 4;
 
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y <= 4 * size; y++)
		{
			double dist1 = sqrt(pow(x - size, 2) + pow(y - size, 2));
			double dist2 = sqrt(pow(x - size, 2) + pow(y - 3 * size, 2));
 
			if (dist1 < size + 0.5 || dist2 < size + 0.5) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
 
	for (int x = 1; x < 2 * size; x++)
	{
		for (int y = 0; y < x; y++) {
			printf(" ");
		}
		
		for (int y = 0; y < 4 * size + 1 - 2 * x; y++)
		{
			if (x >= print_line - 1 && x <= print_line + 1)
			{
				int idx = y - (4 * size - 2 * x - n) / 2;
				if (idx < n && idx >= 0)
				{
					if (x == print_line) {
						printf("%c", message[idx]);
					}
					else {
						printf(" ");
					}
				}
				else {
					printf("*");
				}
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	char	Jahee[100] = "재희";
	char	Hyunwoo[100] = "현우";
	char	Birthday1[100] = "10.22";
	char	Birthday2[100] = "10/22";
	char	message1[100] = "I Love You!";
	char	message2[100] = "Happy Birthday!!";

	for (int i = 1; i < ac; i++)
	{
		if (ft_strstr(av[i], Jahee))
		{
			printf("Beuatiful!!!\n");
			if (ft_strstr(av[i], Hyunwoo))
			{
				printheart(message1);	
			}
			if (ft_strstr(av[i], Birthday1))
			{
				printheart(message2);
			}
			else if(ft_strstr(av[i], Birthday2))
			{
				printheart(message2);
			}
		}
		else if (ft_strstr(av[i], Birthday1))
		{
			printheart(message2);
		}
		else if (ft_strstr(av[i], Birthday2))
		{
			printheart(message2);
		}
		else
		{
			printf("not Beuatiful.\n");
		}
	}	
}
