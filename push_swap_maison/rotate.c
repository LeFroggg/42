/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:23:36 by abastian          #+#    #+#             */
/*   Updated: 2024/09/27 15:17:03 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	rotate(t_node **stack)
{
	t_node	*change;
	t_node	*current;

	change = *stack;
	current = *stack;
	*stack = change->next;
	while (current->next != NULL)
		current = current->next;
	current->next = change;
	change->next = NULL;
}

void	ra(t_node **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_node **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
