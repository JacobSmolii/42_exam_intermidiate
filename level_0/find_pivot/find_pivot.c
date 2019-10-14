/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:19:41 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/26 09:01:54 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int find_pivot(int *arr, int n)
{
	int i;
	int rest;
	int left;

	i = -1;
	rest = 0;
	left = 0;
	while (++i < n)
		rest = rest + arr[i];
	i = 0;

	while (i < n)
	{
		rest = rest - arr[i];
		if (left == rest)
			return (i);
		left = left + arr[i];
		i++;
	}
	return (-1);
}

int main()
{
	int arr[3] = { 7, 9, 8 };
	int n = 3;
	int i;

	i = find_pivot(arr, n);
	printf("%d\n", i);
	// printf("pivot nbr: %d\n", find_pivot(arr, n));

	return (0);
}
