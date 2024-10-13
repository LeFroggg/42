/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:55:38 by abastian          #+#    #+#             */
/*   Updated: 2024/09/30 14:57:34 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **stack_out, t_node **stack_in)
{
	t_node	*change;

	change = *stack_out;
	*stack_out = change->next;
	change->next = *stack_in;
	*stack_in = change;
}

void	pb(t_node **a, t_node **b)
{
	if (!a || !b)
		return ;
	ft_printf("pb\n");
	push(a, b);
}

void	pa(t_node **a, t_node **b)
{
	if (!a || !b)
		return ;
	ft_printf("pa\n");
	push(b, a);
}
