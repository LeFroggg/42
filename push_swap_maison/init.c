/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:47:32 by abastian          #+#    #+#             */
/*   Updated: 2024/09/30 14:57:09 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_node **a, t_node **b, char **argv, int string)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!syntax_error(argv[i]))
			error(a, b, argv, string);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error(a, b, argv, string);
		if (double_check(*a, (int)n) == 1)
			error(a, b, argv, string);
		make_node(a, (int)n);
		i++;
	}
}

void	make_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*current;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (*stack == NULL)
	{
		*stack = node;
	}
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

int	stack_sorted(t_node	**stack)
{
	t_node	*current;

	if (!stack)
		return (1);
	current = *stack;
	while (current->nbr < current->next->nbr)
	{
		if (current->next->next == NULL)
			return (1);
		current = current->next;
	}
	return (0);
}
