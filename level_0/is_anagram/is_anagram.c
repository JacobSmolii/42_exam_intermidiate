/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:45:45 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/25 14:38:29 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_anagram(char *a, char *b)
{
	int		i;
	int		tab[127] = {0};

	i = 0;
	while (a[i] != '\0')
		tab[(int)a[i++]] += 1;
	i = 0;
	while (b[i] != '\0')
		tab[(int)b[i++]] -= 1;
	i = 0;
	while (i < 127)
	{
		if (tab[i++] != 0)
			return (0);
	}
	return (1);
}


int main()
{
	char	*str_1 = ".abca?.";
	char	*str_2 = "?bcab..";

	printf("%d\n", is_anagram(str_1, str_2));

	return (0);
}
