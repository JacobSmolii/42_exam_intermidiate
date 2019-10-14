/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 21:05:55 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/24 15:24:03 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};


int	count_tree(struct s_node *n)
{
	if (!n)
		return (0);
	int count = count_tree(n->left) + count_tree(n->right) + 1;
	return (count);
}

int	split(struct s_node *n, int nbr_tree)
{
	if (!n)
		return (0);
	if (count_tree(n) == nbr_tree - (count_tree(n)))
		return (1);
	return (split(n->left, nbr_tree) || split(n->right, nbr_tree));
}

int can_split(struct s_node *n)
{
	int		nbr_tree = 0;

	nbr_tree = count_tree(n);
	return (split(n, nbr_tree));
}

#include <stdio.h>
#include <stdlib.h>

struct s_node	*init_tree(int data)
{
	struct s_node	*node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main()
{
	struct s_node *root;

	root = init_tree(28);

	root->left = init_tree(51);

	root->left->left = init_tree(26);
	root->left->right = init_tree(48);

	root->left->left->left = init_tree(76);
	root->left->left->right = init_tree(13);

	// another example

	// root = init_tree(1);

	// root->left = init_tree(2);
	// root->right = init_tree(3);

	// root->left->left = init_tree(4);
	// root->left->right = init_tree(7);

	// root->left->left->left = init_tree(5);
	// root->left->left->right = init_tree(6);

	// root->left->right->left = init_tree(9);
	// root->left->right->right = init_tree(10);

	// root->left->left->left->left = init_tree(8);

	// root->left->right->left->left = init_tree(11);
	// root->left->right->left->right = init_tree(12);
	// root->left->right->right->left = init_tree(13);

	// print_tree(root);
	printf("%d\n", can_split(root));
}
