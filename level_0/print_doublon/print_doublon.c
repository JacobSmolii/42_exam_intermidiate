/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:18:04 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/23 13:27:15 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int tmp = -1;

	i = 0;
	j = 0;
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
			printf(tmp++ < 0 ? "%d" : "% d", a[i]);
		if (a[i] > b[j])
			j++;
		else
			i++;
	}
	printf("\n");
}

int main()
{
	int	a[11] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int b[8] = {2,  4,  5,  6,  7, 10,  40,  70};

	int na = 11;
	int nb = 8;
	print_doublon(a, na, b, nb);
	return (0);
}
