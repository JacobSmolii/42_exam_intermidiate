/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:19:55 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/26 09:51:13 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node		*create_node(int data)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void		longest_sequence_help(struct s_node *node, int curLength, int expected, int *rest)
{
	if (!node)
		return ;

	if (node->value == expected)
		curLength++;
	else
		curLength = 1;

	if (curLength > *rest)
		*rest = curLength;

	longest_sequence_help(node->left, curLength, node->value + 1, rest);
	longest_sequence_help(node->right, curLength, node->value, rest);
}



int			longest_sequence(struct s_node *node)
{
	int		rest = 0;

	if (!node)
		return (0);
	longest_sequence_help(node, 0, node->value, &rest);

	return (rest);
}



int main()
{
	struct s_node	*root;

	root = create_node(10);

	root->left = create_node(5);

	root->left->left = create_node(6);
	root->left->right = create_node(9);

	root->left->left->left = create_node(7);
	root->left->left->right = create_node(13);

	root->left->left->left->left = create_node(78);

	// another example

	// root = create_node(5);

	// root->left = create_node(6);
	// root->right = create_node(4);

	// root->right->left = create_node(9);
	// root->right->right = create_node(3);

	// root->right->left->left = create_node(3);
	// root->right->left->right = create_node(2);

	// root->right->right->left = create_node(2);

	// another example

	// root = create_node(30);

	// root->left = create_node(15);
	// root->right = create_node(41);

	// root->left->left = create_node(61);
	// root->right->left = create_node(80);



	printf("%d\n", longest_sequence(root));

	return (0);
}
