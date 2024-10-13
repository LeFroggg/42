/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:29:52 by abastian          #+#    #+#             */
/*   Updated: 2024/09/30 14:58:23 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	start;
	int	end;

	start = 0;
	end = 15;
	if (stacklen(a) == 2)
		sa(a);
	else if (stacklen(a) == 3)
		sort_three(a);
	else if (stacklen(a) == 4)
		sort_four(a, b);
	else if (stacklen(a) == 5)
		sort_five(a, b);
	else
		sort_more(a, b, &start, &end);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min_nbr;

	min_nbr = find_min(a);
	if ((*a)->nbr == min_nbr->nbr)
		pb(a, b);
	else if ((*a)->next->nbr == min_nbr->nbr)
	{
		ra(a);
		pb(a, b);
	}
	else
	{
		while ((*a)->nbr != min_nbr->nbr)
			rra(a);
		pb(a, b);
	}
	if (!stack_sorted(a))
		sort_four(a, b);
	pa(a, b);
}

void	sort_four(t_node **a, t_node **b)
{
	t_node	*min_nbr;

	min_nbr = find_min(a);
	if ((*a)->nbr == min_nbr->nbr)
		pb(a, b);
	else if ((*a)->next->nbr == min_nbr->nbr)
	{
		ra(a);
		pb(a, b);
	}
	else
	{
		while ((*a)->nbr != min_nbr->nbr)
			rra(a);
		pb(a, b);
	}
	if (!stack_sorted(a))
		sort_three(a);
	pa(a, b);
}

void	sort_three(t_node **a)
{
	t_node	*max_nbr;

	max_nbr = find_max(a);
	if ((*a)->nbr == max_nbr->nbr)
		ra(a);
	else if ((*a)->next->nbr == max_nbr->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
