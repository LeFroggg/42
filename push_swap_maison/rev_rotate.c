/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:01:43 by abastian          #+#    #+#             */
/*   Updated: 2024/09/27 15:16:45 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	rev_rotate(t_node **stack)
{
	t_node	*current;
	t_node	*first;

	first = *stack;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	*stack = current->next;
	current->next->next = first;
	current->next = NULL;
}

void	rra(t_node **a)
{
	ft_printf("rra\n");
	rev_rotate(a);
}

void	rrb(t_node **b)
{
	ft_printf("rrb\n");
	rev_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	ft_printf("rrr\n");
	rev_rotate(a);
	rev_rotate(b);
}
