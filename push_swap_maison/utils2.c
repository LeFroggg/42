/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:54:59 by abastian          #+#    #+#             */
/*   Updated: 2024/09/30 15:22:22 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	free_split(char **bigtab)
{
	int	i;

	i = 0;
	if (bigtab == NULL || !(*bigtab))
		return ;
	while (bigtab[i])
	{
		free(bigtab[i]);
		i++;
	}
	free(bigtab);
}

t_node	*find_max(t_node **stack)
{
	int		max;
	t_node	*max_nbr;
	t_node	*current;

	max = INT_MIN;
	max_nbr = NULL;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr > max)
		{
			max_nbr = current;
			max = current->nbr;
		}
		current = current->next;
	}
	return (max_nbr);
}

t_node	*find_min(t_node **stack)
{
	int		min;
	t_node	*min_nbr;
	t_node	*current;

	min = INT_MAX;
	min_nbr = NULL;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr < min)
		{
			min_nbr = current;
			min = current->nbr;
		}
		current = current->next;
	}
	return (min_nbr);
}

int	first_half_check(t_node **b, int nbr, int half_len)
{
	t_node	*current;

	current = *b;
	while (half_len > 0 && current)
	{
		if (current->nbr == nbr)
		{
			return (1);
		}
		current = current->next;
		half_len--;
	}
	return (0);
}
