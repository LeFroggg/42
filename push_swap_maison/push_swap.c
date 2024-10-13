/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:13:36 by abastian          #+#    #+#             */
/*   Updated: 2024/09/30 15:13:33 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		string;
	char	**arguments;

	a = NULL;
	b = NULL;
	string = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!argv[1][0] || !only_space(argv[1]))
			error(&a, &b, argv, string);
		arguments = ft_split(argv[1], ' ');
		string = 1;
		if (!string_check(argv[1]))
			return (free_all(&a, &b, arguments, string), 0);
	}
	else
		arguments = &argv[1];
	init_stack_a(&a, &b, arguments, string);
	if (!stack_sorted(&a))
		sort_stack(&a, &b);
	return (free_all(&a, &b, arguments, string), 0);
}

/*while(a)
	{
		ft_printf("%d\n", a->nbr);
		a = a->next;
	}
	ft_printf("c'est normal tu leaks avec l'impression de la stack\n");*/
