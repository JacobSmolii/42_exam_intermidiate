/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 23:03:40 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/19 17:38:07 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	get_2(int i, int *rest)
{
	if (i > 10)
		get_2(i / 10, rest);
	if (i % 10 == 2)
		(*rest)++;
}

int		count_of_2(int n)
{
	int		rest;
	int		i;

	rest = 0;
	i = 2;
	if (n <= 1)
		return (0);
	while (i <= n)
	{
		get_2(i, &rest);
		i++;
	}
	return (rest);
}



int		main(int ac, char **av)
{
	ac = 1;
	int rest = 0;

	printf("%d\n", count_of_2(atoi(av[1])));

	// get_2(30, &rest);
	// printf("%d\n", rest);
	return (0);
}
