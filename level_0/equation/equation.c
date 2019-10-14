/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:53:32 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/12 12:56:10 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	equation(int n)
{
	int a;
	int b;
	int c;

	a = 0;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			c = 0;
			while (c <= 9)
			{
				if (((a * 10) + b) + ((c * 10) + a) == n)
				{
					printf("A = %d, ", a);
					printf("B = %d, ", b);
					printf("C = %d", c);
					printf("\n");
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

int main(int ac, char **av)
{
	ac = 0;

	equation(atoi(av[1]));
	return (0);
}
