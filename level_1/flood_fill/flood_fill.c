/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:38:19 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/19 13:08:31 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_point
	{
		int		x;
		int		y;
	}				t_point;

void	get_fill(char **tab, t_point size, t_point begin, char c)
{
	if (begin.x >= size.x || begin.y >= size.y || begin.x < 0 || begin.y < 0)
		return ;
	if (tab[begin.y][begin.x] != c)
		return ;
	tab[begin.y][begin.x] = 'F';
	begin.x -= 1;
	get_fill(tab, size, begin, c);
	begin.x += 2;
	get_fill(tab, size, begin, c);
	begin.x -= 1;
	begin.y -= 1;
	get_fill(tab, size, begin, c);
	begin.y += 2;
	get_fill(tab, size, begin, c);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.x >= size.x || begin.y >= size.y || begin.x < 0 || begin.y < 0)
		return ;
	get_fill(tab, size, begin, tab[begin.y][begin.x]);
}


char	**make_area(char **zone, t_point size)
{
	int		i;
	int		j;
	char	**rest;

	i = 0;
	rest = (char **)malloc(sizeof(char *) * size.y);
	while (i < size.y)
	{
		j = 0;
		rest[i] = (char *)malloc(sizeof(char) * (size.x + 1));
		while (j < size.x)
		{
			rest[i][j] = zone[i][j * 2];
			j++;
		}
		i++;
	}
	return (rest);
}

void	print_tab(char **map, t_point size)
{
	int i;
	int j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};

	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};

	area = make_area((char **)zone, size);
	print_tab(area, size);

	// flood_fill(area, size, begin);
	// printf("\n");

	// print_tab(area, size);
	return (0);
}
