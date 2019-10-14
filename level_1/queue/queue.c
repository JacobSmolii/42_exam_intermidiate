/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:58:43 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/19 16:38:18 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void			*content;
	struct s_node	*next;
};

struct s_queue {
	struct s_node	*first;
	struct s_node	*last;
};

struct s_queue *init(void)
{
	struct s_queue *queue;

	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;

	if (!queue->first)
	{
		queue->first = new;
		queue->last = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
}

void *dequeue(struct s_queue *queue)
{
	struct s_node	*tmp;
	void			*data;

	if (!queue->first)
		return (NULL);
	tmp = queue->first;
	data = tmp->content;

	queue->first = tmp->next;
	free(tmp);
	return (data);
}

void *peek(struct s_queue *queue)
{
	if (!queue->first)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	return ((!queue->first) ? 1 : 0);
}

#include <stdio.h>

// int main()
// {
// 	struct s_queue	*queue;

// 	queue = init();
// 	printf("Empty? %d\n", isEmpty(queue));

// 	enqueue(queue, "Hello");
// 	printf("Empty? %d\n", isEmpty(queue));
// 	printf("Peeking: %s\n", peek(queue));

// 	enqueue(queue, "World");
// 	printf("Empty? %d\n", isEmpty(queue));
// 	printf("Peeking: %s\n", peek(queue));

// 	enqueue(queue, ":)");
// 	printf("Empty? %d\n", isEmpty(queue));
// 	printf("Peeking: %s\n", peek(queue));

// 	printf("Dequeue: %s\n", dequeue(queue));
// 	printf("Dequeue: %s\n", dequeue(queue));
// 	printf("Dequeue: %s\n", dequeue(queue));
// 	printf("Dequeue: %s\n", dequeue(queue));

// 	printf("Empty? %d\n", isEmpty(queue));
// 	return (0);
// }

int main(void)
{
    struct s_queue  *queue = init();
    char            *content[][1] = {
      "Eins",
      "Zwei",
      "Drei",
      "Vier",
      "Funf"
    };
    for (int i = 0; i < 5; i += 1)
    {
        enqueue(queue, *content[i]);
        printf("Content : %s\n", peek(queue));
        printf("Empty   : %s\n", (isEmpty(queue) ? "yes" : "no"));
    }
	printf("\n\n");
    for (int i = 5; i > 0; i -= 1)
    {
        dequeue(queue);
        printf("Content : %s\n", peek(queue));
        printf("Empty   : %s\n", (isEmpty(queue) ? "yes" : "no"));
    }
    return (0);
}
