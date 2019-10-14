/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:15:19 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/31 20:30:00 by vsmolii          ###   ########.fr       */
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

struct s_node		*init_tree(int data)
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	print_leaves(struct s_node *node)
{
	if (!node)
		return ;
	print_leaves(node->left);
	if (!node->left && !node->right)
		printf("% d" , node->value);
	print_leaves(node->right);
}

void	print_left_perimeter(struct s_node *node)
{
	if (!node)
		return ;
	if (node->left || (!node->left && node->right))
	{
		printf("% d", node->value);
		print_left_perimeter(node->left);
	}
}

void	print_right_perimeter(struct s_node *node)
{
	if (!node || (!node->left && !node->right))
		return ;
	print_right_perimeter(node->right);
	printf("% d", node->value);
}

void 	perimeter(struct s_node *root)
{
	if (!root)
		return ;
	printf("%d", root->value);

	print_left_perimeter(root->left);
	print_leaves(root->left);
	print_leaves(root->right);
	print_right_perimeter(root->right);
	printf("\n");
}


int	main()
{
	struct s_node *root;

	root = init_tree(92);

	root->left = init_tree(85);
	root->right = init_tree(26);

	root->left->left = init_tree(79);
	root->right->right = init_tree(64);

	root->left->left->right = init_tree(10);
	root->right->right->left = init_tree(40);
	root->right->right->right = init_tree(78);

	root->left->left->right->left = init_tree(39);
	root->right->right->left->left = init_tree(88);
	root->right->right->left->right = init_tree(10);
	root->right->right->right->left = init_tree(2);
	root->right->right->right->right = init_tree(85);

	root->left->left->right->left->left = init_tree(35);
	root->right->right->left->left->left = init_tree(12);
	root->right->right->left->left->right = init_tree(55);
	root->right->right->left->right->left = init_tree(52);
	root->right->right->left->right->right = init_tree(87);
	root->right->right->right->left->left = init_tree(33);
	root->right->right->right->left->right = init_tree(11);
	root->right->right->right->right->right = init_tree(51);

	root->left->left->right->left->left->left = init_tree(96);
	root->right->right->left->left->left->left = init_tree(58);
	root->right->right->left->left->right->left = init_tree(58);
	root->right->right->left->left->right->right = init_tree(41);
	root->right->right->left->right->left->left = init_tree(22);
	root->right->right->left->right->left->right = init_tree(35);
	root->right->right->left->right->right->right = init_tree(31);
	root->right->right->right->left->left->right = init_tree(55);
	root->right->right->right->left->right->left = init_tree(99);

	perimeter(root);
	return (0);
}
