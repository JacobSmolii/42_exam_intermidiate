
#include <stdlib.h>

struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
};

struct s_node	*create_node(int content)
{
	struct s_node	*new = malloc(sizeof(struct s_node));
	new->data = content;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

struct s_node	*clone_prev_list(struct s_node	*node, struct s_node *list)
{
	struct s_node	*tmp = list;
	if (!list)
		return (create_node(node->data));
	else
	{
		while (list->next)
			list = list->next;
		list->next = create_node(node->data);
	}
	return (tmp);
}

struct s_node *find_proper_node(struct s_node *node, struct s_node *list, struct s_node *other)
{
	int				i = 0;
	int				j = 0;
	struct s_node	*tmp = node;
	struct s_node	*tmp_list = list;
	while (tmp)
	{
		i++;
		if (tmp == other)
			break ;
		tmp = tmp->next;
	}
	while (tmp_list)
	{
		j++;
		if (j == i)
			return (tmp_list);
		tmp_list = tmp_list->next;
	}
	return (NULL);
}

struct s_node *clone_list(struct s_node *node)
{
	if (!node)
		return (NULL);
	struct s_node	*list = NULL;
	struct s_node	*tmp_list;
	struct s_node	*tmp_node = node;
	while (tmp_node)
	{
		list = clone_prev_list(tmp_node, list);
		tmp_node = tmp_node->next;
	}
	tmp_node = node;
	tmp_list = list;
	while (tmp_node)
	{
		if (tmp_node->other)
			tmp_list->other = find_proper_node(node, list, tmp_node->other);
		tmp_list = tmp_list->next;
		tmp_node = tmp_node->next;
	}

	return (list);
}

#include <stdio.h>


void	print_list(struct s_node *head)
{
	while (head)
	{
		printf("Node: %p\nData: %d\nOther: %p; ", head, head->data, head->other);
		if (head->other)
			printf("%d", head->other->data);
		printf("\n---\n");
		head = head->next;
	}
}

// int main()
// {
// 	struct s_node	*list = NULL;
// 	struct s_node	*clone = NULL;

// 	list = create_list(1);
// 	list->next = create_list(2);
// 	list->next->next = create_list(3);
// 	list->next->next->next = create_list(4);
// 	list->next->next->next->next = create_list(5);
// 	list->next->next->next->next->next = create_list(6);

// 	list->next->next->next->next->next->other = list->next->next->next->next; //5
// 	list->next->next->next->next->other = list->next; //2
// 	list->next->next->next->other = list->next->next; //3
// 	list->next->next->other = list->next->next; //3

// 	print_list(list);
// 	printf("------------------\n");
// 	clone = clone_list(list);
// 	print_list(clone);

// }


int		main(void)
{
	struct s_node *head = create_list(5);
	head->next = create_list(10);
	head->next->next = create_list(15);
	head->next->next->next = create_list(20);
	head->next->next->next->next = create_list(25);
	head->next->next->next->next->next = create_list(30);

	head->next->next->next->next->next->other = head->next->next->next->next; //25
	head->next->next->next->next->other = head; //5
	head->next->next->next->other = head->next; //10
	head->next->next->other = head->next->next; //15
	print_list(head);
	printf("\n\n");

	struct s_node *clone = clone_list(head);

	print_list(clone);
}
