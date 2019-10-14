#include <unistd.h>
#include <stdlib.h>

static int longest_path;

int		ft_atoi(char **str)
{
	int nbr = 0;

	while (**str >= '0' && **str <= '9')
	{
		nbr = (nbr * 10) + **str - 48;
		(*str)++;
	}
	if (**str)
		(*str)++;
	return (nbr);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = n % 10 + 48;
	write(1, &c, 1);
}

void	find_path(int max, u_int8_t arr[max][max], u_int8_t path[max], int y, int len)
{
	int x = 0;

	/* mark vertix y as visited */
	path[y] = 1;
	x = -1;
	/* iterate through columns */
	while (++x < max)
	{
		/*	if the edge found and the paired vertix isn't yet visited,
			increment len for this edge and run recursion for the corresponding paired vertix (row) */
		if (arr[y][x] && path[x] == 0)
		{
			if (longest_path < len + 1)
				longest_path = len + 1;
			find_path(max, arr, path, x, len + 1);
		}
	}
	path[y] = 0;
}

void	create_graph(char *str, int max)
{
	int 	x = 0;
	int 	y = 0;
	uint8_t	arr[max][max];
	uint8_t	path[max];

	y = -1;
	/* initialize matrix */
	while (++y < max)
	{
		x = -1;
		while (++x < max)
			arr[y][x] = 0;
	}
	y = -1;
	/* initialize the path */
	while (++y < max)
		path[y] = 0;
	/* filling the matrix with the corresponding vertecies from the input */
	while (*str)
	{
		y = ft_atoi(&str);
		x = ft_atoi(&str);
		arr[y][x] = 1;
		arr[x][y] = 1;
	}
	y = -1;
	while (++y < max)
		find_path(max, arr, path, y, 1);
}

void	g_diam(char *str)
{
	int 	i = 0;
	int 	max = 0;
	char	*tmp = str;

	while (*tmp)
	{
		/* need to find the biggest nbr for our matrix size */
		i = ft_atoi(&tmp);
		max = (i > max) ? i : max;
	}
	longest_path = 2;
	/* increment max++ for [0] position of the ararys */
	max++;
	create_graph(str, max);
	ft_putnbr(longest_path);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		g_diam(av[1]);
	else
		write(1, "\n", 1);
}
