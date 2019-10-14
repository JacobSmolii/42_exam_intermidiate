/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 19:07:17 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/25 12:28:57 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		count_volume(int *histogram, int start, int end)
{
	int count = 0;
	while (start <= end)
	{
		if (histogram[start] == 0)
			count++;
		if (histogram[start] > 0)
		{
			histogram[start]--;

		}
		start++;
	}
	return (count);
}

int    volume_histogram(int *histogram, int size)
{
	int i = 0;
	int	start = -1;
	int	end = -1;
	int	count = 0;

	while (i < size)
	{
		if (histogram[i] > 0)
		{
			if (start == -1)
				start = i;
			else
				end = i;
		}
		if (start != -1 && end != -1 && i == size -1)
		{
			count += count_volume(histogram, start, end);
			start = -1;
			end = -1;
			i = 0;
		}
		else
			i++;
	}
	return (count);
}

#include <stdio.h>

int main()
{
	// int		histogram[52] = {2, 0, 0, 5, 6, 6, 5, 0, 0, 8, 9, 0, 5, 0, 0, 4, 0, 7, 0, 8, 0, 9, 0, 3, 0, 1, 0, 5, 0, 5, 0, 6, 0, 4, 0, 6, 0, 7, 0, 5, 5, 6, 5, 4, 7, 0, 8, 0, 5, 0, 0, 0};
	// int		size = 52;
	int		histogram[16] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	int		size = 16;
	// int		histogram[5] = {1, 0, 2, 0, 2};
	// int		size = 5;

	printf("%d\n", volume_histogram(histogram, size));

}
