/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:37:12 by msalim            #+#    #+#             */
/*   Updated: 2024/10/21 14:26:35 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, int value)
{
	t_Node	*node;

	node = malloc(sizeof(t_Node));
	if (!node)
		return ;
	node->value = value;
	node->next = a->top;
	a->top = node;
	a->size++;
}

void	push_b(t_stack *a, t_stack *b)
{
	int	value;

	if (a->top == NULL)
		return ;
	value = pop(a);
	push(b, value);
	write(1, "pb\n", 3);
}

void	push_a(t_stack *a, t_stack *b)
{
	int	value;

	if (b->top == NULL)
		return ;
	value = pop(b);
	push(a, value);
	write(1, "pa\n", 3);
}
