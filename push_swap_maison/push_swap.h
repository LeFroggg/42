/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:13:59 by abastian          #+#    #+#             */
/*   Updated: 2024/09/30 15:23:35 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
}	t_node;

//Errors
int		error(t_node **a, t_node **b, char **argv, int string);
int		syntax_error(char	*argument);
int		double_check(t_node *a, int nbr);
int		string_check(char *str);
int		only_space(char *str);

//Stack things
void	make_node(t_node **stack, int n);
void	init_stack_a(t_node **a, t_node **b, char **argv, int string);
void	free_stack(t_node **stack);
void	index_init(t_node **stack, int len);
int		stack_sorted(t_node	**stack);
long	ft_atol(const char *nptr);
int		stacklen(t_node **stack);
t_node	*find_max(t_node **stack);
t_node	*find_min(t_node **stack);
void	free_split(char **bigtab);
void	free_all(t_node **a, t_node **b, char **argv, int string);
int		first_half_check(t_node **b, int nbr, int half_len);

//Moves
void	sa(t_node	**a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//Algo
void	sort_stack(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_more(t_node **a, t_node **b, int *start, int *end);

#endif
