/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:21:04 by abastian          #+#    #+#             */
/*   Updated: 2024/09/30 15:21:59 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i + 1] == ' ')
				i++;
			if (str[i + 1] != '\0')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	stacklen(t_node **stack)
{
	t_node	*current;
	int		i;

	i = 1;
	current = *stack;
	if (!stack || !(*stack))
		return (0);
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

static void	index_void(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
}

void	index_init(t_node **stack, int len)
{
	int		i;
	int		min;
	t_node	*current;
	t_node	*checkpoint;

	index_void(stack);
	i = 1;
	while (len > 0)
	{
	min = INT_MAX;
	current = *stack;
		while (current)
		{
			if (current->nbr < min && current->index == 0)
			{
				min = current->nbr;
				checkpoint = current;
			}
			current = current->next;
		}
		checkpoint->index = i;
		i++;
		len--;
	}
}
