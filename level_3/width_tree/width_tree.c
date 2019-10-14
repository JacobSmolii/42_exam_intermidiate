/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:33:45 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/26 10:03:43 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		recurs(struct s_node *n, int *max_width)
{
	if (!n)
		return (0);
	int	left = recurs(n->left, max_width); // фун-я доходит сначало до конца по левой ветке, как только видит тупик,
	int	right = recurs(n->right, max_width); //  возвращается на лист выше и пытается проверить все что есть по правой стороне
	int	local_len = 1 + (left > right ? left : right); // длина делается на текущем ноде, в самом конце будет 1, а потом будет увеличиваться на единицу.
	int	local_width = 1 + (left + right); //  Так же смотрит с какой стороны будет больше длина(слква или справа) (это своего рода фу-я)
	if (local_width > *max_width) //
		*max_width = local_width;
	return (local_len); // всегда возвращает длину. И в конечном итоге это будет наш финальный результат
}

int		width_tree(struct s_node *n)
{
	int		max_width = 0;
	recurs(n, &max_width);
	return (max_width);
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

	root = init_tree(1);

	root->left = init_tree(2);
	root->right = init_tree(5);

	root->left->left = init_tree(3);
	root->left->right = init_tree(4);

	root->right->left = init_tree(7);
	root->right->right = init_tree(8);

	root->left->right->left = init_tree(6);

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
	printf("%d\n", width_tree(root));
}
