/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:04:10 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/31 19:34:26 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*to_lower(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return (tmp);
}

int		count_char(char *str, char c)
{
	int		count = 0;

	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int		check_char(char *str, char c, int j)
{
	int	i = 0;

	while (i < j)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	count_alpha(char *str)
{
	int		i = 0;
	int		flag = -1;

	str = to_lower(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && check_char(str, str[i], i))
			printf(flag++ < 0 ? "%d%c" : ", %d%c", count_char(str, str[i]), str[i]);
		i++;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	else
		printf("\n");
	return (0);
}
