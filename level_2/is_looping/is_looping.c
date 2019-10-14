/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:06:12 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/28 13:57:19 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int				value;
	struct s_node	*next;
};

int 	is_looping(struct s_node *node)
{
	struct s_node	*list1 = node;
	struct s_node	*list2 = node;
	while (list1 && list2)
	{
		list1 = list1->next;
		list2 = list2->next;

		if (list2)
			list2 = list2->next;
		if (list1 && list2 && list1 == list2)
			return (1);
	}
	return (0);
}

struct s_node *create_list(int v) {
	struct s_node *new = malloc(sizeof(struct s_node));
	new->value = v;
	new->next = 0;
	return new;
}

int main()
{
	struct s_node *list = create_list(1);

	list->next = create_list(2);
	list->next->next = create_list(3);
	list->next->next->next = create_list(4);
	list->next->next->next->next = list;

	printf("%d\n", is_looping(list));

	struct s_node *c = create_list(1);
	c->next = create_list(2);
	c->next->next = create_list(3);
	c->next->next->next = create_list(4);

	printf("%d\n", is_looping(c));

	return 0;
}
