/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:35:04 by vsmolii           #+#    #+#             */
/*   Updated: 2019/10/04 12:20:04 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		gold_gain(int **mine, int n)
{
	int i;
	int j = 1;
	int max = 0;
	int tmp;

	if (!mine)
		return (0);
	while (j < n)
	{
		i = 0;
		while (i <= n - 1)
		{
			if (i == 0)
				mine[i][j] += ft_max(mine[i][j - 1], mine[i + 1][j - 1]);
			else if (i == n - 1)
				mine += ft_max(mine[i][j - 1], mine[i - 1][j - 1]);
			else
			{
				tmp = ft_max(mine[i + 1][j - 1], mine[i][j - 1]);
				mine += ft_max(tmp, mine[i - 1][j - 1]);
			}
		}
		j++;
	}
	i = 0;
	while (i < n)
	{
		if (mine[i][n - 1] > max)
			max = mine[i][n - 1];
		i++;
	}
	return (max);
}




int		**make_area(int *zone, int n)
{
	int		i;
	int		j;
	int		**rest;

	i = -1;
	rest = (int **)malloc(sizeof(int *) * n);
	while (++i < n)
	{
		j = -1;
		rest[i] = (int *)malloc(sizeof(int) * n);
		while (++j < n)
			rest[i][j] = zone[i * n + j];
	}
	return (rest);
}


int main()
{
	int		n = 3;
	int		arr[] = {1, 0, 0, 0, 3, 4, 0, 0, 0};
	int		**mine = make_area(arr, n);


	printf("%d\n", gold_gain(mine, n));
}
