/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:41:49 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/25 13:35:30 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
		void *content;
		struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node	*tmp = lst2;

	while (lst1)
	{
		tmp = lst2;
		while (tmp)
		{
			if (lst1 == tmp)
				return (lst1);
			tmp = tmp->next;
		}
		lst1 = lst1->next;
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

struct s_node *create_list()
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = 0;
	new->next = NULL;
	return (new);
}

int	main()
{
	struct s_node	*list_1;

	list_1 = create_list();
	list_1->next = create_list();
	list_1->next->next = create_list();
	list_1->next->next->next = create_list();
	list_1->next->next->next->next = create_list();

	struct s_node	*list_2;

	list_2 = create_list();
	list_2->next = create_list();
	list_2->next->next = create_list();
	list_2->next->next->next = create_list();
	list_2->next->next->next->next = create_list();

	printf("%p\n", intersection(list_1, list_2));

	list_1->next->next->next->next = list_2->next->next->next->next;
	printf("%p\n", intersection(list_1, list_2));

	return (0);
}
