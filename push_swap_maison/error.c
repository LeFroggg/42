/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:50:19 by abastian          #+#    #+#             */
/*   Updated: 2024/09/27 15:08:53 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_node **a, t_node **b, char **argv, int string)
{
	free_stack(a);
	free_stack(b);
	if (string == 1)
	{
		free_split(argv);
		argv = NULL;
	}
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error(t_node **a, t_node **b, char **argv, int string)
{
	write(2, "Error\n", 6);
	free_all(a, b, argv, string);
	exit(1);
}

int	syntax_error(char *argument)
{
	int	i;

	i = 0;
	if (argument[i] == '+' || argument[i] == '-')
	{
		if (!(argument[i + 1] >= '0' && argument[i + 1] <= '9'))
			return (0);
		i++;
	}
	while (argument[i])
	{
		if (!(argument[i] >= '0' && argument[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	double_check(t_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
