/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 23:34:14 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/21 20:23:24 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORG_ALPALONG_H
# define ORG_ALPALONG_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_split
{
	int				w_len;
	char			*word;
	struct s_split	*next;
}				t_split;

int			space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

int			ft_strlen(char *word)
{
	int		len = 0;
	while (word[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int		i = 0;
	char	*dest;

	while (str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_word(char *str, int w_start, int w_end)
{
	int		i = 0;
	char	*new = (char *)malloc(sizeof(char) * (w_end - w_start) + 1);

	while (w_start < w_end)
	{
		new[i] = str[w_start];
		w_start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

t_split		*add_list(t_split *list, char *word)
{
	t_split		*newNode;
	t_split		*tmp;

	tmp = list;
	newNode = (t_split *)malloc(sizeof(t_split));
	newNode->w_len = ft_strlen(word);
	newNode->word = word;
	newNode->next = NULL;
	if (!list)
		return (newNode);
	else
	{
		while (list->next)
			list = list->next;
		list->next = newNode;
		return (tmp);
	}
}

void		ft_swap_node_content(t_split **node_1, t_split **node_2)
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

t_split		*sort_by_len(t_split *list)
{
	t_split		*tmp = list;

	while (tmp && tmp->next)
	{
		if (tmp->w_len > tmp->next->w_len)
		{
			ft_swap_node_content(&tmp, &tmp->next);
			tmp = list;
		}
		else
			tmp = tmp->next;
	}
	return (list);
}

#endif
