/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:45:57 by abastian          #+#    #+#             */
/*   Updated: 2024/10/16 17:09:35 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	name_check(char *name)
{
	int	i;

	i = 0;
	while(name[i])
		i++;
	i--;
	if (name[i] == 'r')
		i--;
	else
		return (0);
	if (name[i] == 'e')
		i--;
	else
		return (0);
	if (name[i] == 'b')
		i--;
	else
		return (0);
	if (name[i] == '.' && name[i - 1] != '\0')
		return (1);
	return (0);
}

int	each_line_check(char *getmap, t_game *game)
{
	int	i;

	i = 0;
	if (getmap[0] == '\n')
		return(1);
	while(getmap[i])
	{
		if(getmap[i] == '\n' && getmap[i + 1] == '\n')
			return(1);
		i++;
	}
	return (0);
}

int	is_wrong_data(char data, char *allowed)
{
	int	i;

	i = 0;
	while(allowed[i])
	{
		if (data == allowed[i])
			return (1);
		i++;
	}
	return (0);
}

void	init_elem(t_game *game)
{
	game->map.C = 0;
	game->map.P = 0;
	game->map.E = 0;
	game->map.total = 0;
}

void	check_elem(t_game *game)
{
	if (game->map.C < 1 || game->map.E < 1 || game->map.P < 1)
		error_game("You need at least one exit, one item and one player in your map configuration", game);
	if (game->map.P > 1 && game->map.E > 1)
		error_game("There is more than one player and one exit in your map configuration", game);
	else if (game->map.P > 1)
		error_game("There is more than one player in your map configuration", game);
	else if (game->map.E > 1)
		error_game("There is more than one exit in your map configuration", game);
	else
		game->map.total = (game->map.C + game->map.P + game->map.E); // utile ?
}
