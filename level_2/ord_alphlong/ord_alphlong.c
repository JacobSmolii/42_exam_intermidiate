/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:06:24 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/26 09:20:15 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

void		ft_swap_node(t_split **node_1, t_split **node_2)
{
	int		len_swap;
	char	*word_swap;

	len_swap = (*node_1)->w_len;
	(*node_1)->w_len = (*node_2)->w_len;
	(*node_2)->w_len = len_swap;

	word_swap = (*node_1)->word;
	(*node_1)->word = (*node_2)->word;
	(*node_2)->word = word_swap;
}

char		*change_to_lower(char *str)
{
	char *tmp = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (tmp);
}

int			check_ascii(t_split *n1, t_split *n2)
{
	char	*str_1 = change_to_lower(ft_strdup(n1->word));
	char	*str_2 = change_to_lower(ft_strdup(n2->word));

	while (*str_1 && *str_2)
	{
		if (*str_1 == *str_2)
		{
			str_1++;
			str_2++;
			continue ;
		}
		if (*str_1 > *str_2)
			return (1);
		else
			break ;
	}
	return (0);
}

t_split		*sort_by_ascii(t_split *list)
{
	t_split		*tmp = list;

	while (tmp && tmp->next)
	{
		if (tmp->w_len == tmp->next->w_len)
		{
			if (check_ascii(tmp, tmp->next))
			{
				ft_swap_node_content(&tmp, &tmp->next);
				tmp = list;
			}
		}
		tmp = tmp->next;
	}
	return (list);
}


void		print_list(t_split *list)
{
	int		flag = -1;

	while (list && list->next)
	{
		if (flag++ < 0)
			write(1, list->word, list->w_len);
		else
		{
			write(1, " ", 1);
			write(1, list->word, list->w_len);
		}

		if (list->w_len < list->next->w_len)
		{
			write(1, "\n", 1);
			flag = -1;
		}
		list = list->next;
	}
	if (list && !list->next)
	{
		if (flag != -1)
			write(1, " ", 1);
		write(1, list->word, list->w_len);
			write(1, "\n", 1);
	}
}


void		ord_alphlong(char *str)
{
	int 		i = 0;
	int 		w_start = 0;
	int 		w_end = 0;
	t_split		*list = NULL;

	while (str[i])
	{
		if ((i == 0 || space_tab(str[i - 1])) && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
			w_start = i;
		if ((str[i + 1] == '\0' || space_tab(str[i])) && ((str[i - 1] >= 'a' && str[i - 1] <= 'z') || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')))
			w_end = i;
		if (w_start < w_end)
		{
			if (str[i + 1] == '\0')
				w_end++;
			list = add_list(list, get_word(str, w_start, w_end));
			w_start = 0;
			w_end = 0;
		}
		i++;
	}
	list = sort_by_len(list);
	list = sort_by_ascii(list);
	print_list(list);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ord_alphlong(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
