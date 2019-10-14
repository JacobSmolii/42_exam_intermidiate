/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:15:12 by vsmolii           #+#    #+#             */
/*   Updated: 2019/08/16 12:51:19 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void			*content;
	struct s_node	*next;
};

struct s_stack {
	struct s_node	*top;
};


struct s_stack *init(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	struct s_node	*tmp;
	void			*data;

	if (!stack->top)
		return (NULL);
	tmp = stack->top;
	data = tmp->content;
	stack->top = tmp->next;
	free(tmp);
	return (data);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!stack->top)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	return ((!stack->top) ? 1 : 0);
}

#include <stdio.h>

int main()
{
	struct s_stack *stack;

	stack = init();
	printf("Empty? %d\n", isEmpty(stack));

	push(stack, "Hello");
	printf("Empty? %d\n", isEmpty(stack));
	printf("Peeking: %s\n", peek(stack));

	push(stack, "World");
	printf("Empty? %d\n", isEmpty(stack));
	printf("Peeking: %s\n", peek(stack));

	push(stack, ":)");
	printf("Empty? %d\n", isEmpty(stack));
	printf("Peeking: %s\n", peek(stack));

	printf("Popped: %s\n", pop(stack));
	printf("Popped: %s\n", pop(stack));
	printf("Popped: %s\n", pop(stack));
	printf("Popped: %s\n", pop(stack));

	printf("Empty? %d\n", isEmpty(stack));

	return (0);
}
