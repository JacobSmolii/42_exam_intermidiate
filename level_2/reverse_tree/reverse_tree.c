/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:05:44 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/19 16:38:18 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void	print_tree(struct s_node *root, int space)
{
	int		i = 10;

	space += 10;
	if (!root)
		return ;
	print_tree(root->right, space);
	printf("\n");
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf("%d\n", root->value);
	print_tree(root->left, space);
}


void	print_b_tree(struct s_node *root)
{
	print_tree(root, 0);
}

struct s_node	*init_btree(int data)
{
	struct s_node	*node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void reverse_tree(struct s_node *root)
{
	struct s_node	*tmp;

	if (root)
	{
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		if (root->left)
			reverse_tree(root->left);
		if (root->right)
			reverse_tree(root->right);
	}
	return ;
}

int		main()
{
	struct s_node		*root;

	root = init_btree(94);

	root->left = init_btree(34);
	root->right = init_btree(52);

	root->left->left = init_btree(1);
	root->left->right = init_btree(99);

	root->left->left->left = init_btree(20);

	root->left->right->left = init_btree(83);
	root->left->right->right = init_btree(39);

	root->left->right->left->left = init_btree(61);

	root->left->right->right->left = init_btree(37);
	root->left->right->right->right = init_btree(67);

	print_b_tree(root);
	reverse_tree(root);
	printf("-------------------------\n");
	print_b_tree(root);
	return (0);
}
