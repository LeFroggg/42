/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:37 by abastian          #+#    #+#             */
/*   Updated: 2024/11/04 17:08:02 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_list(t_list **msg)
{
	t_list	*current;

	current = *msg;
	while (current)
	{
		ft_printf("%c", *(char *)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

void	free_all(t_list **msg)
{
	t_list	*temp;

	while ((*msg))
	{
		temp = *msg;
		free((*msg)->content);
		(*msg)->content = NULL;
		*msg = (*msg)->next;
		free(temp);
		temp = NULL;
	}
}
