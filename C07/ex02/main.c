/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:53:41 by hoh               #+#    #+#             */
/*   Updated: 2021/10/24 14:28:03 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern int ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int *range;

	range = 0;
	printf("%d\n", ft_ultimate_range(&range, 1, -7));
	if (!range)
	{
		printf("널");
		return (0);
	}
	for (int i=0;i<6;i++)
		printf("%d", range[i]);
	free(range);

	/*각 요소의 길이가 정해지지 않은2차원 배열을 만드려면?
	 * 그렇게 만들어진 배열은 **arr와 같이 더블포인터로 넘길 수 있는가?
	 * arr[2][2] 를 함수의 인자로 넘기는 경우vs *arr[]를 함수의 인자로 넘기는 경우*/
}
