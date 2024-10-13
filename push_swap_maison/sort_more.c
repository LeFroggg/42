/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:18:01 by abastian          #+#    #+#             */
/*   Updated: 2024/09/27 15:28:22 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_next(t_node **a, t_node **b)
{
	int		half;
	t_node	*checkpoint;

	checkpoint = NULL;
	while (*b)
	{
		checkpoint = find_max(b);
		half = first_half_check(b, checkpoint->nbr, (stacklen(b) / 2));
		while ((*b)->nbr != checkpoint->nbr)
		{
			if (half == 1)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_more(t_node **a, t_node **b, int *start, int *end)
{
	index_init(a, stacklen(a));
	while (*a)
	{
		if ((*a)->index <= (*start))
		{
			pb(a, b);
			rb(b);
			(*start)++;
			(*end)++;
		}
		else if ((*a)->index > (*start) && (*a)->index < (*end))
		{
			pb(a, b);
			(*start)++;
			(*end)++;
		}
		else if ((*a)->index >= (*end))
			ra(a);
	}
	sort_next(a, b);
}
