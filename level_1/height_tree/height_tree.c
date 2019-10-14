/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:08:51 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/28 11:06:15 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int				value;
	struct s_node	**nodes;
};

int		count_tree(struct s_node *el)
{
	int		i;
	int		max;
	int		count;

	i = 0;
	count = 0;
	max = 0;
	while (el->nodes && el->nodes[i])
	{
		count = count_tree(el->nodes[i]) + 1;
		if (count > max)
			max = count;
		i += 1;
	}
	return (max);
}

int		height_tree(struct s_node *root)
{
	int		rest;

	rest = -1;
	if (root)
		rest = count_tree(root);
	return (rest);
}


struct s_node	*newNode(int data)
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = data;
	new->nodes = malloc(10000);
	return (new);
}

int main()
{
	struct s_node	*root;

	root = newNode(94);

	root->nodes[0] = newNode(34);
	root->nodes[1] = newNode(52);

	root->nodes[0]->nodes[0] = newNode(1);
	root->nodes[0]->nodes[1] = newNode(99);
	root->nodes[0]->nodes[2] = newNode(11);

	root->nodes[0]->nodes[1]->nodes[0] = newNode(13);

	// root->nodes[0]->nodes[1]->nodes[0]->nodes[0] = newNode(2);
	// root->nodes[0]->nodes[0]->nodes[0]->nodes[0] = newNode(3);

	printf("height = %d\n", height_tree(root));
	return (0);
}
